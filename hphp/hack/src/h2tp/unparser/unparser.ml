(**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the "hack" directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 *)

(* generated by ocamltarzan *)

module R = Str
open Ast
open Unparsed
open Utils
open Common_exns


(*
  =============================================================================
  Unparsing is fairly complicated, especially with a language like php which has
  many nuances. Instead of implementing the entire unparser at one go, I prefer to
  implement it piecemeal as I come across constructs I care about for task at hand.

  At the same time I do not want to depend on wildcards to identify what's not been
  unparsed and I want the error message when I cannot unparse something to be clear.

  To that extend I'm using ocamltarzan to generate the scaffold for the unparser,
  it recursively unparses each element of every construct, but also raises TODO
  by default until the particular construct is implemented.

  Here are some helper functions for the same.
  =================================================================================
*)
(*
These are todo constructs for which we will choose not to fail but to
    instead return the default which is known to be incorrect or incomplete
*)
let ok_todos = set_of_list [
  "mode";
]

(*
  The first argument is the error message to raise and the second argument is
  the autogenerated code that is not useful. The reason we retain the autogenerated
  code is to not have to regenerate it later, and at the same time to not have it
  return unused warnings.
*)
let u_todo msg pregen_fn =
  if SSet.mem msg ok_todos
  then pregen_fn ()
  else raise(Todo ("unsupported construct in Unparser:  " ^ msg))

(*
  This is a more nuanced variation of u_todo. It accepts a list of
  (cond, msg, pregen_fn), in each case, if the condition is true, we call
  u_todo with the msg and pregen_fn, but when its false we fall through.
  This makes it easier to implement just parts of the unparser for complex constructs
  (like class definitions)
*)
let u_todo_conds todos else_fn =
  match (List.find ~f:(fun (cond, _, _) -> cond) todos) with
    | Some (_, msg, fn) -> u_todo msg fn
    | None -> else_fn ()

(*
  env is something that is used while unparsing so that we can handle special issues
  where the code that is unparsed depends implicitly on the structure of some
  condition of the ancestors in the AST rather than just the current node.

  Examples are modes and namespaces. Currently I've introduced mode as an example.
*)
type unparse_env = {
  mutable mode: FileInfo.mode
}

(*
  functions and methods have a lot in common, but their own peculiarities also.
  This captures all the common stuff to prevent having to repeat it while
  unparsing.
*)
type fun_common = {
  fc_tparams         : tparam list;
  fc_ret             : hint option;
  fc_ret_by_ref          : bool;
  fc_name            : id;
  fc_params          : fun_param list;
  fc_body            : block;
  fc_user_attributes : user_attribute list;
  fc_fun_kind        : fun_kind;
}

(* for expressions that contain sub-expressions, this identifies
  if the sub-expression needs to be parenthesised when it is inside another expression
*)
type shouldParens = YES | NO | TODO of string

let is_associative = function
  | Plus | Star | AMpamp | BArbar | Dot
  | Amp | Bar | Xor -> true
  | Minus | Slash | Lt | Lte | Gt | Gte | Starstar
  | Eqeq | EQeqeq | Diff | Diff2 | Ltlt
  | Gtgt | Percent | Eq _ -> false

module Unparse = struct
(*
  unparsers for simple and predefined types.
*)
let u_of_list_spc u_of_elem elems =
  List.map ~f:u_of_elem elems |>
  fun x -> StrWords x

let u_of_list_comma u_of_elem elems =
  List.map ~f:u_of_elem elems |>
  fun x -> StrCommaList x

let u_of_list_parens_comma u_of_elem elems =
  List.map ~f:u_of_elem elems |>
  fun x -> StrParens (StrCommaList x)

let u_of_list_braces_spc u_of_elem elems =
  List.map ~f:u_of_elem elems |>
  fun x -> StrBraces (StrWords x)

let u_of_bool b = Str (if b then "true" else "false")

let u_of_float f = Str (string_of_float f)

let u_of_option f = function
  | Some x -> f x
  | None -> StrEmpty

let u_of_string str = Str str

(*
  unparser for the AST. Autogenerated with ocamltarzan
*)

let dummy_unparse_fn = fun () -> StrEmpty

let u_file_type =
  function
  | FileInfo.PhpFile -> Str "<?php"
  | FileInfo.HhFile -> Str "<?hh"

let u_pos_t _ = StrEmpty

let u_id (_pos, s) =
  Str s

let u_pstring (_pos, s) =
  Str s

let u_var_name (_pos, s) =
  Str ("$" ^ s)

let u_of_smap _ _ = u_todo "smap"  (fun () -> StrEmpty)

let is_empty_ns ns =
  (* FIXME: Don't use the default popt *)
  if (ns = Namespace_env.empty ParserOptions.default) then true else false

let rec u_program v = u_of_list_spc u_def v
  and u_in_mode _ f = u_todo "mode" f
  and u_def =
    function
    | Fun fun_ -> u_fun_ fun_
    | Class v2 -> u_class_ v2
    | Stmt stmt -> u_stmt stmt
    | Typedef v2 ->
        u_todo "Typedef"
          (fun () ->
             let v1 = Str "Typedef" and v2 = u_typedef v2 in StrWords [ v1; v2 ])
    | Constant v2 -> u_gconst v2
    | Namespace (id, program) ->
        let strProgram = u_program program
        in StrWords [Str "namespace"; u_id id; StrBraces strProgram]
    | NamespaceUse uses ->
        let u_use (kind, (p1, ns), (p2, name)) =
          let ns_end = List.last_exn (R.split (R.regexp "\\\\") ns) in
          let qualifier = if ns_end <> name
                          then [Str "as"; u_id (p2, name)]
                          else [] in
          let id_and_qualifier = u_id (p1, ns) :: qualifier in
          let kind_id_and_qualifier = match kind with
            | NSClass -> id_and_qualifier
            | NSFun -> Str "function" :: id_and_qualifier
            | NSConst -> Str "const" :: id_and_qualifier in
          StrStatement (Str "use" :: kind_id_and_qualifier) in
        u_of_list_spc u_use uses
  and
    u_typedef {
                t_id = (pos, _) as v_t_id;
                t_tparams = v_t_tparams;
                t_constraint = v_t_constraint;
                t_kind = v_t_kind;
                t_user_attributes = v_t_user_attributes;
                t_namespace = v_t_namespace;
                t_mode = v_t_mode
              } =
    invariant (is_empty_ns v_t_namespace)
      (pos, "Namespaces are expected to not be elaborated");
    u_todo "typedef"
      (fun () ->
        u_in_mode v_t_mode (fun () ->
          u_todo_conds [
            (v_t_user_attributes <> [], "t_user_attributes",
              (fun () -> u_of_smap u_user_attribute v_t_user_attributes)) ;
          ] (fun () ->
            let v_t_id = u_id v_t_id in
            let v_t_tparams = u_of_list_spc u_tparam v_t_tparams in
            let v_t_constraint = u_tconstraint v_t_constraint in
            let v_t_kind = u_typedef_kind v_t_kind in
              StrWords [v_t_id; v_t_tparams; v_t_constraint; v_t_kind])))
  and
    u_gconst {
               cst_mode = v_cst_mode;
               cst_kind = v_cst_kind;
               cst_name = (pos, _) as v_cst_name;
               cst_type = v_cst_type;
               cst_value = v_cst_value;
               cst_namespace = v_cst_namespace
             } =
    u_in_mode v_cst_mode (fun () ->
      invariant (is_empty_ns v_cst_namespace)
        (pos, "Namespaces are expected to not be elaborated");
      let v_cst_value = u_expr v_cst_value in
      match v_cst_kind with
      | Cst_const ->
          let v_cst_name = u_id v_cst_name in
          let v_cst_type = u_of_option u_hint v_cst_type in
          StrStatement [
            Str "const";
            v_cst_type;
            v_cst_name;
            Str "=";
            v_cst_value
          ]
      | Cst_define ->
          invariant (v_cst_type = None) (pos, "Constants using the define " ^
            "syntax cannot use type hints");
          StrStatement [
            Str "define";
            StrParens (StrCommaList [
              u_expr_ (String v_cst_name);
              v_cst_value;
            ])
          ])
  and u_variance =
    function
    | Covariant -> u_todo "Covariant" (fun () -> StrEmpty )
    | Contravariant -> u_todo "Contravariant" (fun () -> StrEmpty )
    | Invariant -> u_todo "Invariant" (fun () -> StrEmpty )
  and u_constraint_kind =
    function
    | Constraint_as -> u_todo "as" (fun () -> StrEmpty)
    | Constraint_eq -> u_todo "=" (fun () -> StrEmpty)
    | Constraint_super -> u_todo "super" (fun () -> StrEmpty)
  and u_tparam (v2, v3, v4) =
    u_todo "tparam"
      (fun () ->
         let v1 = Str "tparam"
         and v2 = u_variance v2
         and v3 = u_id v3
         and v4 = u_of_list_spc (fun (ck, h) ->
           StrWords [u_constraint_kind ck; u_hint h]) v4
         in StrWords [ v1; v2; v3; v4 ])
  and u_tconstraint v = u_of_option u_hint v
  and u_typedef_kind =
    function
    | Alias v2 ->
        u_todo "Alias"
          (fun () ->
             let v1 = Str "Alias" and v2 = u_hint v2 in StrWords [ v1; v2 ])
    | NewType v2 ->
        u_todo "NewType"
          (fun () ->
             let v1 = Str "NewType" and v2 = u_hint v2 in StrWords [ v1; v2 ])
  and
    u_class_ {
               c_mode = v_c_mode;
               c_user_attributes = v_c_user_attributes;
               c_final = v_c_final;
               c_kind = v_c_kind;
               c_is_xhp = v_c_is_xhp;
               c_name = (pos, _) as v_c_name;
               c_tparams = v_c_tparams;
               c_extends = v_c_extends;
               c_implements = v_c_implements;
               c_body = v_c_body;
               c_namespace = v_c_namespace;
               c_enum = v_c_enum;
               c_span = _;
             } =
      u_in_mode v_c_mode (fun () ->
          invariant (List.length v_c_extends <= 1 || v_c_kind = Cinterface)
            (pos, "Multiple inheritance is not supported.");
          invariant (is_empty_ns v_c_namespace)
            (pos, "Namespaces are expected to not be elaborated");
        u_todo_conds [
          (v_c_is_xhp, "c_is_xhp", (fun () -> u_of_bool v_c_is_xhp)) ;
          (not (List.is_empty v_c_tparams), "c_tparams", (fun () -> u_of_list_spc u_tparam v_c_tparams)) ;
          (v_c_user_attributes <> [], "c_user_attributes",
            (fun () -> u_of_smap u_user_attribute v_c_user_attributes)) ;
          (Option.is_some v_c_enum, "c_enum", (fun () -> u_of_option u_enum_ v_c_enum))
        ] (fun () ->
          let u_elt = u_class_elt v_c_kind in
          let str_c_final = if v_c_final then Str "final" else StrEmpty in
          let str_c_kind = u_class_kind v_c_kind in
          let str_c_name = u_id v_c_name in
          let str_c_body = u_of_list_braces_spc u_elt v_c_body in
          let str_c_extends = u_extends v_c_extends in
          let str_c_implements = u_implements v_c_implements in
            StrWords [
              str_c_final;
              str_c_kind;
              str_c_name;
              str_c_extends;
              str_c_implements;
              str_c_body;
            ]))
  and u_extends = function
    | [] -> StrBlank
    | hints -> StrWords [Str "extends"; u_of_list_comma u_hint hints]
  and u_implements = function
  | [] -> StrEmpty
  | implements -> StrWords [Str "implements"; u_of_list_comma u_hint implements]
  and u_enum_ { e_base = v_e_base; e_constraint = v_e_constraint } =
    u_todo "enum_"
      (fun () ->
         let v_e_base = u_hint v_e_base in
         let v_e_constraint = u_of_option u_hint v_e_constraint
         in StrWords [ v_e_base; v_e_constraint ])
  and u_user_attribute v = u_of_list_spc u_expr v
  and u_class_kind =
    function
    | Cabstract -> StrWords [Str "abstract"; Str "class"]
    | Cnormal -> Str "class"
    | Cinterface -> Str "interface"
    | Ctrait -> Str "trait"
    | Cenum -> u_todo "Cenum" (fun () -> StrEmpty)
  and u_trait_req_kind =
    function
    | MustExtend -> Str "extends"
    | MustImplement -> Str "implements"
  and u_class_elt kind =
    function
    | Const (hOption, decls) ->
      let hOptionStr = u_of_option u_hint hOption
      and declsStr = u_of_list_comma (fun (id, expr) ->
        StrWords [ u_id id; Str "="; u_expr expr]) decls
      in StrStatement [ Str "const" ; hOptionStr; declsStr ]
    | AbsConst (hOption, name) ->
      let hOptionStr = u_of_option u_hint hOption
      and nameStr = u_id name
      in StrStatement [ Str "abstract const" ; hOptionStr; nameStr ]
    | Attributes v2 ->
        u_todo "Attributes"
          (fun () ->
             let v1 = Str "Attributes"
             and v2 = u_of_list_spc u_class_attr v2
             in StrWords [ v1; v2 ])
    | ClassUse hint ->
        StrStatement [Str "use"; u_hint hint]
    | XhpAttrUse hint ->
        StrStatement [Str "attribute"; u_hint hint]
    | ClassTraitRequire (trait_req_kind, hint) ->
        StrStatement [
          Str "require";
          u_trait_req_kind trait_req_kind;
          u_hint hint;
        ]
    | ClassVars (kinds, hintOption, classVars) ->
        let kindStr = u_of_list_spc u_kind kinds
        and hintStr = u_of_option u_hint hintOption
        and varStr = u_of_list_comma u_class_var classVars in
        StrStatement [kindStr; hintStr; varStr]
    | XhpAttr _ ->
        u_todo "XhpAttr" (fun () -> StrEmpty)
    | XhpCategory _ ->
        u_todo "XhpCategory" (fun () -> StrEmpty)
    | Method m -> u_method_ kind m
    | TypeConst _ -> u_todo "TypeConst" (fun () -> StrEmpty)

  and u_class_attr =
    function
    | CA_name v2 ->
        u_todo "CA_name"
          (fun () ->
             let v1 = Str "CA_name" and v2 = u_id v2 in StrWords [ v1; v2 ])
    | CA_field v2 ->
        u_todo "CA_field"
          (fun () ->
             let v1 = Str "CA_field"
             and v2 = u_ca_field v2
             in StrWords [ v1; v2 ])
  and
    u_ca_field {
                 ca_type = v_ca_type;
                 ca_id = v_ca_id;
                 ca_value = v_ca_value;
                 ca_required = v_ca_required
               } =
    u_todo "ca_field"
      (fun () ->
         let v_ca_type = u_ca_type v_ca_type in
         let v_ca_id = u_id v_ca_id in
         let v_ca_value = u_of_option u_expr v_ca_value in
         let v_ca_required = u_of_bool v_ca_required
         in StrWords [ v_ca_type; v_ca_id; v_ca_value; v_ca_required ])
  and u_ca_type =
    function
    | CA_hint v2 ->
        u_todo "CA_hint"
          (fun () ->
             let v1 = Str "CA_hint" and v2 = u_hint v2 in StrWords [ v1; v2 ])
    | CA_enum v2 ->
        u_todo "CA_enum"
          (fun () ->
             let v1 = Str "CA_enum"
             and v2 = u_of_list_spc u_of_string v2
             in StrWords [ v1; v2 ])
  and u_kind kind =
    let s = match kind with
      | Final -> "final"
      | Static -> "static"
      | Abstract -> "abstract"
      | Private -> "private"
      | Public -> "public"
      | Protected -> "protected" in
    Str s
  and u_class_var (_, id, exprOpt) =
    let exprStr = match exprOpt with
      | None -> StrEmpty
      | Some expr -> StrWords [Str "=" ; u_expr expr] in
    StrWords [u_var_name id; exprStr]
  and
    u_method_ class_kind {
      m_kind;
      m_tparams;
      m_name;
      m_params;
      m_constrs = _;
      m_body;
      m_user_attributes;
      m_ret;
      m_ret_by_ref;
      m_fun_kind;
      m_span = _;
    } =
      let str_m_kind = u_of_list_spc u_kind m_kind
      and v_f_common = {
        fc_tparams = m_tparams;
        fc_ret = m_ret;
        fc_ret_by_ref = m_ret_by_ref;
        fc_name = m_name;
        fc_params = m_params;
        fc_body = m_body;
        fc_user_attributes = m_user_attributes;
        fc_fun_kind = m_fun_kind;
      }
      and is_abstract = class_kind = Cinterface || List.mem m_kind Abstract in
      StrWords [str_m_kind; u_fun_common v_f_common StrEmpty u_id is_abstract]
  and
    u_fun_param {
                  param_hint = v_param_hint;
                  param_is_reference = v_param_is_reference;
                  param_is_variadic = v_param_is_variadic;
                  param_id = v_param_id;
                  param_expr = v_param_expr;
                  param_modifier = v_param_modifier;
                  param_user_attributes = v_param_user_attributes
                } =
     u_todo_conds [
       (v_param_user_attributes <> [], "param_user_attributes",
         fun () -> u_of_smap u_user_attribute v_param_user_attributes);
     ] begin fun () ->
         let str_param_mod = u_of_option u_kind v_param_modifier
         and str_param_hint = u_of_option u_hint v_param_hint
         and str_param_id = u_id v_param_id in
         let str_param_id = if v_param_is_reference
                            then StrList [Str "&"; str_param_id]
                            else str_param_id in
         let str_param_id =
          match (v_param_is_variadic, str_param_id) with
          | (true, Str "...") (* hack variadic *) | (false, _) -> str_param_id
          | (true, _) -> StrList [Str "..."; str_param_id] in
         let str_param_expr = match v_param_expr with
         | None -> StrEmpty
         | Some e -> StrWords [Str "="; u_expr e] in
         StrWords [ str_param_mod; str_param_hint; str_param_id; str_param_expr]
      end
      (* We have to treat the use clause specially because its in the middle of
        a function, but only used by lambdas.
      *)
  and u_fun_name name_parser id =
    match u_id id with
      | Str ";anonymous" -> StrEmpty
      | _ -> name_parser id
  and u_fun_common {
    fc_tparams;
    fc_ret;
    fc_ret_by_ref;
    fc_name;
    fc_params;
    fc_body;
    fc_user_attributes;
    fc_fun_kind;
  } useStr u_of_name abstract =
    u_todo_conds [(
      fc_user_attributes <> [],
      "m_user_attributes",
      (fun () -> u_of_smap u_user_attribute fc_user_attributes)
    )] begin fun () ->
        let str_tparams = match fc_tparams with
          | [] -> StrEmpty
          | _ -> u_todo "fc_tparams" (fun () -> StrList [Str "<"; u_of_list_comma u_tparam fc_tparams; Str ">"])
        and str_params = u_of_list_parens_comma u_fun_param fc_params
        and str_body = if abstract then StrSemi else u_block fc_body
        and str_ret = match fc_ret with
          | None -> StrEmpty
          | Some r -> StrWords [Str ":"; u_hint r]
        and str_fun_kind = u_fun_kind fc_fun_kind
        and str_name = u_fun_name u_of_name fc_name in
        let str_name = if fc_ret_by_ref
                       then StrList [Str "&"; str_name]
                       else str_name in
          StrWords [
            str_fun_kind;
            Str "function";
            str_name;
            str_tparams;
            str_params;
            useStr;
            str_ret ;
            str_body;
          ]
    end

  and u_fun_with_use {
    f_mode;
    f_tparams;
    f_ret;
    f_ret_by_ref;
    f_name = (pos, _) as f_name;
    f_params;
    f_body;
    f_user_attributes;
    f_fun_kind;
    f_namespace;
    f_span = _;
  } useStr =
    u_in_mode f_mode begin fun () ->
      invariant (is_empty_ns f_namespace)
        (pos, "Namespaces are expected to not be elaborated");
      u_fun_common {
        fc_tparams = f_tparams;
        fc_ret = f_ret;
        fc_ret_by_ref = f_ret_by_ref;
        fc_name = f_name;
        fc_params = f_params;
        fc_body = f_body;
        fc_user_attributes = f_user_attributes;
        fc_fun_kind = f_fun_kind;
      } useStr (u_id) false
    end
  and
    u_fun_ fun_ = u_fun_with_use fun_ StrEmpty
  and u_fun_kind =
    function
    | FAsync | FAsyncGenerator -> Str "async"
    | FSync | FGenerator -> StrEmpty
  and u_hint (v2, v3) = StrList [u_pos_t v2; u_hint_ v3]
  and u_hint_ =
    function
    | Hoption hint -> StrList [Str "?"; u_hint hint]
    | Hfun ((v2, v3, v4)) ->
        u_todo "Hfun"
          (fun () ->
             let v1 = Str "Hfun"
             and v2 = u_of_list_spc u_hint v2
             and v3 = u_of_bool v3
             and v4 = u_hint v4
             in StrWords [ v1; v2; v3; v4 ])
    | Htuple v2 ->
        u_todo "Htuple"
          (fun () ->
             let v1 = Str "Htuple"
             and v2 = u_of_list_spc u_hint v2
             in StrWords [ v1; v2 ])
    | Happly (v2, v3) ->
        u_todo_conds [
          (List.length v3 <> 0, "Happly", (fun () -> u_of_list_spc u_hint v3))
        ] (fun () -> u_id v2)
    | Hshape v2 ->
        u_todo "Hshape"
          (fun () ->
             let v1 = Str "Hshape"
             and v2 = u_of_list_spc u_shape_field v2
             in StrWords [ v1; v2 ])
    | Haccess _ -> u_todo "Haccess" (fun () -> StrEmpty)
  and u_shape_field_name =
    function
    | SFlit v2 ->
        u_todo "SFlit"
          (fun () ->
             let v1 = Str "SFlit" and v2 = u_pstring v2 in StrWords [ v1; v2 ])
    | SFclass_const ((v2, v3)) ->
        u_todo "SFclass_const"
          (fun () ->
             let v1 = Str "SFclass_const"
             and v2 = u_id v2
             and v3 = u_pstring v3
             in StrWords [ v1; v2; v3 ])
  and u_shape_field (v2, v3) =
    u_todo "shape_field"
      (fun () ->
         let v1 = Str "shape_field"
         and v2 = u_shape_field_name v2
         and v3 = u_hint v3
         in StrWords [ v1; v2; v3 ])
  and u_stmt stmt =
    let stmtStr = match stmt with
      | Unsafe -> StrComment "UNSAFE"
      | Fallthrough -> StrComment "FALLTHROUGH"
      | Expr expr -> u_expr expr
      | Block stmts -> u_block stmts
      | Break _pos -> Str "break"
      | Continue _pos -> Str "continue"
      | Throw expr -> StrWords [Str "throw"; u_expr expr]
      | Return (_pos, exprOpt) ->
          let exprStr = u_of_option u_expr exprOpt in
          StrWords [ Str "return"; exprStr]
      | Static_var exprList ->
          StrWords [Str "static"; u_of_list_comma u_expr exprList;]
      | If (cond, thenExpr, elseExpr) ->
          let condStr = StrParens (u_expr cond)
          and thenStr = u_block thenExpr
          and elseStr = match elseExpr with
          | [Noop] -> StrEmpty
          | _ -> StrWords [Str "else"; u_block elseExpr]
          in StrWords [ Str "if"; condStr; thenStr; elseStr ]
      | Do (block, expr) ->
          StrWords [
            Str "do";
            u_block block;
            Str "while";
            StrParens (u_expr expr)
          ]
      | While (expr, block) ->
          StrWords [
            Str "while";
            StrParens (u_expr expr);
            u_block block;
          ]
      | For (initExpr, testExpr, loopExpr, block) ->
          StrWords [
            Str "for";
            StrParens (StrSemiList [
              u_expr initExpr;
              u_expr testExpr;
              u_expr loopExpr;
            ]);
            u_block block;
          ]
      | Switch (expr, cases) ->
          StrWords [
            Str "switch";
            StrParens (u_expr expr);
            u_of_list_braces_spc u_case cases;
          ]
      | Foreach (expr, _posOption, as_expr, block) ->
          StrWords [
            Str "foreach";
            StrParens (StrWords [
              u_expr expr ;
              u_as_expr as_expr ;
            ]);
            u_block block;
          ]
      | Try (try_block, catches, finally_block) ->
          dn (string_of_int (List.length finally_block));
          let strFinally = match finally_block with
          | [] | [Noop] -> StrEmpty
          | _ -> StrWords [Str "finally"; u_block finally_block] in
          StrWords [Str "try"; u_block try_block; u_of_list_spc u_catch catches; strFinally]
      | Noop -> StrEmpty in
    match stmt with
      | Noop
      | Block _
      | If _
      | For _
      | Switch _
      | Foreach _
      | While _
      | Try _
      | Unsafe
      | Fallthrough -> stmtStr
      | Do _
      | Expr _
      | Break _
      | Continue _
      | Throw _
      | Return _
      | Static_var _ -> StrStatement [stmtStr]

  and u_catch (hint, var, block) =
    StrWords [
      Str "catch";
      StrParens (u_of_list_spc u_id [hint; var;]);
      u_block block;
    ]

  and u_as_expr =
    function
    | As_v expr -> StrWords [Str "as"; u_expr expr]
    | As_kv (kExpr, vExpr) -> StrWords [Str "as"; u_expr kExpr; Str "=>"; u_expr vExpr]
  and u_block v = match v with
    | [Block v] -> u_block v
    | _ -> u_of_list_braces_spc u_stmt v
  and u_naked_block v = u_of_list_spc u_stmt v
  (*
    unparses an expression nested inside another expression.
    introduces an additional set of parens if necessary.
  *)
  and u_expr_nested (_pos, expr_) =
    let res = u_expr_ expr_ in
    let todo_with s = u_todo ("Parens " ^ s) (fun () -> res) in
    match expr_ with
      | Array _
      | Null
      | True
      | False
      | Id _
      | Lvar _
      | Lvarvar _
      | Array_get _
      | Class_get _
      | Class_const _
      | Call _
      | Int _
      | Float _
      | String _
      | String2 _
      | List _
      | Obj_get _
      | Unsafeexpr _ -> res
      | Collection _
      | Cast _
      | Unop _
      | Binop _
      | Pipe _
      | Eif _
      | NullCoalesce _
      | InstanceOf _
      | New _
      | Efun _
      | Lfun _
      | Yield _
      | Yield_break
      | Expr_list _
      | Clone _
      | Import _
      | Await _ -> StrParens res
      | Shape _ -> todo_with "shape"
      | Xml _ -> todo_with "xml"
      | Dollardollar -> todo_with "Dollardollar"
  and u_expr (_pos, expr_) = u_expr_ expr_
  and u_expr_ =
    function
    | Array v2 -> StrList [Str "array"; u_of_list_parens_comma u_afield v2]
    | Shape v2 ->
        u_todo "Shape"
          (fun () ->
             let v1 = Str "Shape"
             and v2 =
               u_of_list_spc
                 (fun (v2, v3) ->
                    u_todo "expr_"
                      (fun () ->
                         let v1 = Str "expr_"
                         and v2 = u_shape_field_name v2
                         and v3 = u_expr v3
                         in StrWords [ v1; v2; v3 ]))
                 v2
             in StrWords [ v1; v2 ])
    | Dollardollar ->
        u_todo "Dollardollar"
          (fun () ->
            Str "$$")
    | Collection (id, afields) ->
      let idStr = u_id id
      and fieldStr = StrBraces (u_of_list_comma u_afield afields) in
      StrWords [idStr; fieldStr;]
    | Null -> Str "null"
    | True -> Str "true"
    | False -> Str "false"
    | Id id -> u_id id
    | Lvar lvar -> u_id lvar
    | Lvarvar (n, lvar) -> begin
      let p, var_id = lvar in
      u_id (p, (String.make n '$') ^ var_id)
    end
    | Clone expr -> StrWords [Str "clone"; u_expr_nested expr]
    | Obj_get (objExpr, itemExpr, null_flavor) ->
        let objStr = u_expr_nested objExpr
        and itemStr = u_expr itemExpr
        and operString = match null_flavor with
        | OG_nullthrows -> "->"
        | OG_nullsafe -> "?->"
        in StrList [ objStr; Str operString; itemStr ]
    | Array_get (exprArr, exprKey) ->
      let exprArrStr = u_expr_nested exprArr
      and exprKeyStr = u_of_option u_expr exprKey in
      StrList [exprArrStr; Str "["; exprKeyStr; Str "]"]
    | Class_get (hintExpr, getExpr) ->
        let hintStr = u_id hintExpr
        and getStr = u_pstring getExpr in
        StrList [hintStr; Str "::"; getStr]
    | Class_const (hintExpr, constExpr) ->
        let hintStr = u_id hintExpr
        and constStr = u_pstring constExpr in
        StrList [hintStr; Str "::"; constStr]
    | Call (funExpr, paramExprs, unpackParamExprs) ->
      let funStr = u_expr_nested funExpr in
      let paramStr = match funStr with
      | Str "echo" when List.length paramExprs > 1 ->
        if unpackParamExprs <> [] then
          u_todo "echo with ... ?" (fun () -> StrEmpty)
        else StrList [StrBlank; u_of_list_comma u_expr paramExprs]
      | _ ->
        let listExprs =
          (List.map ~f:u_expr paramExprs) @
            (List.map ~f:(fun e -> StrList [Str "..." ; u_expr e]) unpackParamExprs) in
        StrParens (StrCommaList listExprs)
      in StrList [ funStr; paramStr ]
    | Int i -> u_pstring i
    | Float f -> u_pstring f
    | String (p, s) ->
      StrList [Str "\""; u_pstring (p, Php_escaping.escape s); Str "\""]
    | String2 [elem] -> StrList [u_expr elem; Str ".\"\""]
    | String2 elems ->
      (* build the string back by concatenating the parts *)
      List.map ~f:u_expr elems |>
      fun els -> StrList (List.intersperse ~sep:(Str ".") els)
    | Yield afield ->
        StrWords [Str "yield"; u_afield afield]
    | Yield_break -> u_todo "Yield_break" (fun () -> StrEmpty)
    | Await v2 ->
        StrWords [Str "await"; u_expr v2]
    | List exprs ->
        StrList [Str "list"; u_of_list_parens_comma u_expr exprs]
    | Expr_list exprs ->
        u_of_list_comma u_expr exprs
    | Cast (hint, expr) ->
        StrList [StrParens (u_hint hint); u_expr_nested expr];
    | Unop (uop, expr) -> u_uop expr uop
    | Binop (bop, e1, e2) -> u_bop e1 e2 bop
    (** The pipe ID is only used for typechecking phase. *)
    | Pipe (e1, e2) -> u_pipe e1 e2
    | Eif (condExpr, trueExprOption, falseExpr) ->
        StrWords [
          u_expr_nested condExpr;
          Str "?";
          u_of_option u_expr_nested trueExprOption;
          Str ":";
          u_expr_nested falseExpr;
        ]
    | NullCoalesce (trueExpr, falseExpr) ->
        StrWords [
          u_expr_nested trueExpr;
          Str "??";
          u_expr_nested falseExpr;
        ]
    | InstanceOf (instExpr, hintExpr) ->
        StrWords [
          u_expr_nested instExpr;
          Str "instanceof";
          u_expr_nested hintExpr;
        ];
    | New (klass, paramExprs, unpackParamExprs) ->
      let klassStr = u_expr klass in
      let listExprs =
        (List.map ~f:u_expr paramExprs) @
          (List.map ~f:(fun e -> StrList [Str "..." ; u_expr e]) unpackParamExprs) in
      let paramStr = StrParens (StrCommaList listExprs) in
      StrList [ Str "new"; StrBlank ; klassStr; paramStr]
    | Efun (fun_, uselist) ->
      let useStr = match uselist with
        | [] -> StrEmpty
        | _ -> StrList [Str "use"; u_of_list_parens_comma u_use uselist] in
      u_fun_with_use fun_ useStr
    | Lfun v2 ->
        u_todo "Lfun"
          (fun () ->
             let v1 = Str "Lfun" and v2 = u_fun_ v2 in StrWords [ v1; v2 ])
    | Xml ((v2, v3, v4)) ->
        u_todo "Xml"
          (fun () ->
             let v1 = Str "Xml"
             and v2 = u_id v2
             and v3 =
               u_of_list_spc
                 (fun (v2, v3) ->
                    u_todo "expr_"
                      (fun () ->
                         let v1 = Str "expr_"
                         and v2 = u_id v2
                         and v3 = u_expr v3
                         in StrWords [ v1; v2; v3 ]))
                 v3
             and v4 = u_of_list_spc u_expr v4
             in StrWords [ v1; v2; v3; v4 ])
    | Unsafeexpr expr ->
        StrWords [Str "/* UNSAFE_EXPR */"; u_expr expr]
    | Import (flavor, expr) ->
        StrWords [u_import_flavor flavor; StrParens (u_expr expr)]
  and u_import_flavor =
    function
    | Require -> Str "require"
    | Include -> Str "include"
    | RequireOnce -> Str "require_once"
    | IncludeOnce -> Str "include_once"
  and u_use (id, is_ref) =
    let str_id = u_id id
    and str_ref = if is_ref then Str "&" else StrBlank
    in StrList [str_ref; str_id]
  and u_afield =
    function
    | AFvalue v2 -> u_expr v2
    | AFkvalue (kExpr, vExpr) -> StrWords [u_expr kExpr; Str "=>"; u_expr vExpr]
  and u_bop e1 e2 bop =
      let bop_str = function
        | Plus -> Str "+"
        | Minus -> Str "-"
        | Star -> Str "*"
        | Starstar -> Str "**"
        | Slash -> Str "/"
        | Eqeq -> Str "=="
        | EQeqeq -> Str "==="
        | AMpamp -> Str "&&"
        | BArbar -> Str "||"
        | Lt -> Str "<"
        | Lte -> Str "<="
        | Gt -> Str ">"
        | Gte -> Str ">="
        | Dot -> Str "."
        | Amp -> Str "&"
        | Bar -> Str "|"
        | Ltlt -> Str "<<"
        | Gtgt -> Str ">>"
        | Percent -> Str "%"
        | Xor -> Str "^"
        | Diff -> Str "!="
        | Diff2 -> Str "!=="
        | _ -> raise Impossible in
      match bop with
      | Eq b -> StrWords [
                  u_expr e1;
                  StrList [u_of_option bop_str b; Str "="];
                  u_expr e2
                ]
      | _ ->
          let e1 = u_expr_in_bop bop e1 in
          let e2 = u_expr_in_bop bop e2 in
          let s = bop_str bop in
          StrWords [e1; s; e2]
  and u_expr_in_bop bop expr =
    match expr with
    | (_, Binop (b,_,_)) when bop = b && is_associative bop -> u_expr expr
    | _ -> u_expr_nested expr
  and u_pipe e1 e2 =
    StrWords [u_expr e1; Str "|>"; u_expr e2]
  and u_uop expr uop =
        let prefix_with s = StrList [Str s; u_expr_nested expr] in
        match uop with
        | Upincr -> StrList [u_expr_nested expr; Str "++"]
        | Updecr -> StrList [u_expr_nested expr; Str "--"]
        | Utild -> prefix_with "~"
        | Unot -> prefix_with "!"
        | Uplus -> prefix_with "+"
        | Uminus -> prefix_with "-"
        | Uincr -> prefix_with "++"
        | Udecr -> prefix_with "--"
        | Uref -> prefix_with "&"
  and u_case v =
    let case_expr name block =
      StrWords [name; Str ":"; u_naked_block block;] in
    match v with
    | Default block ->
        case_expr (Str "default") block
    | Case (expr, block) ->
        case_expr (StrWords [Str "case"; u_expr expr;]) block
      let unparser _env = u_program
end

open Unparse

let unparse_internal program =
  (*
    we feed the output of the unparser to the hack formatter which only
    accepts files with hh prefix, so we have to fake it.
  *)
  StrWords [
    u_file_type FileInfo.HhFile;
    unparser {mode = FileInfo.Mdecl} program
  ]

let unparse :
    FileInfo.file_type -> Path.t -> program -> string =
    fun filetype file program ->
  unparse_internal program |>
  to_string |>
  fun s ->
    dn s;
    let modes = [Some FileInfo.Mstrict; Some FileInfo.Mpartial] in
    let formatted = Format_hack.program modes file ~no_trailing_commas:true s in
    let s' = match formatted with
    | Format_hack.Disabled_mode -> raise Impossible
    | Format_hack.Internal_error -> raise (FormatterError "")
    | Format_hack.Success s' -> s'
    | Format_hack.Parsing_error error -> raise (FormatterError
      ("parsing error \n" ^ (Errors.to_string (Errors.to_absolute
      (List.hd_exn error))))) in
    match filetype with
     | FileInfo.HhFile -> s'
     | FileInfo.PhpFile ->  let r = R.regexp "<\\?hh" in
                   R.replace_first r "<?php" s'
