(**
 * Copyright (c) 2016, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Ast

let rec check_lvalue errorf = function
  | pos, Obj_get (_, (_, Id (_, _)), OG_nullsafe) ->
    errorf pos "?-> syntax is not supported for lvalues"
  | pos, Obj_get (_, (_, Id (_, name)), _) when name.[0] = ':' ->
    errorf pos "->: syntax is not supported for lvalues"
  | _, Array_get ((_, Call _), _) ->
    (* FIXME: Function calls are not supposed to be valid in general cases,
     * but some functions return references which are valid lvalues, we accept
     * all of them here. *)
    ()
  | _, Array_get ((_, Obj_get (_, (_, Id (_, name)), _)), _) when name.[0] = ':' ->
    (* FIXME: Attributes accessed via ->: are not supposed to be valid in
     * general cases, but some attributes are references which are valid lvalues,
     * we accept all of them here. *)
    ()
  | _, Array_get (lvalue, _) ->
    check_lvalue errorf lvalue
  | _, (Lvar _ | Obj_get _ | Class_get _ |
    Unsafeexpr _ | Omitted | BracedExpr _ | Dollar _) -> ()
  | pos, Call ((_, Id (_, "tuple")), _, _, _) ->
    errorf pos "Tuple cannot be used as an lvalue. Maybe you meant list?"
  | _, List el -> List.iter (check_lvalue errorf) el
  | pos, (Array _ | Darray _ | Varray _ | Shape _ | Collection _
    | Null | True | False | Id _ | Clone _
    | Class_const _ | Call _ | Int _ | Float _ | PrefixedString _
    | String _ | String2 _ | Yield _ | Yield_break | Yield_from _
    | Await _ | Suspend _ | Expr_list _ | Cast _ | Unop _
    | Binop _ | Eif _ | InstanceOf _
    | New _ | NewAnonClass _ | Efun _ | Lfun _
    | Xml _ | Import _ | Pipe _ | Callconv _ | Is _ | Execution_operator _ | As _
    | ParenthesizedExpr _) ->
      errorf pos "Invalid lvalue"
