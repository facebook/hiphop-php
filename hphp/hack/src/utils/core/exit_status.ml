(*
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

(** care: the integers provided by deriving-enum should not be exposed
to callers, and are not the same as the 'exit-code' function.
We use deriving-enum solely to power exit_code_to_string. *)
type t =
  | No_error
  | Checkpoint_error
  | Input_error
  | Kill_error
  | No_server_running_should_retry
  | Server_hung_up_should_retry
  | Server_hung_up_should_abort
  | Out_of_time
  | Out_of_retries
  | Server_already_exists
  | Type_error
  | Build_id_mismatch
  | Monitor_connection_failure
  | Unused_server
  | Lock_stolen
  | Lost_parent_monitor
  | Interrupted
  | Worker_oomed
  | Worker_busy
  (* An uncaught Not_found exception in the worker. *)
  | Worker_not_found_exception
  | Worker_failed_to_send_job
  | Socket_error
  | Missing_hhi
  | Dfind_died
  | Dfind_unresponsive
  | EventLogger_Timeout
  | EventLogger_restart_out_of_retries
  | EventLogger_broken_pipe
  | CantRunAI
  | Watchman_failed
  (* It is faster to exit the server (and have the Monitor restart the server)
   * on a Watchman fresh instance than to compute the files that have been
   * deleted and do an incremental check.
   *)
  | Watchman_fresh_instance
  | Watchman_invalid_result
  | File_provider_stale
  | Hhconfig_deleted
  | Hhconfig_changed
  | Server_shutting_down_due_to_sigusr2
  | IDE_malformed_request
  | IDE_no_server
  | IDE_out_of_retries
  | Nfs_root
  | IDE_init_failure
  | IDE_typechecker_died
  | Redecl_heap_overflow
  | Out_of_shared_memory
  | Shared_mem_assertion_failure
  | Hash_table_full
  | IDE_new_client_connected
  | Lazy_decl_bug
  | Decl_heap_elems_bug
  | Parser_heap_build_error
  | Heap_full
  | Sql_assertion_failure
  | Local_type_env_stale
  | Sql_cantopen
  | Sql_corrupt
  | Sql_misuse
  | Uncaught_exception
  | Decl_not_found
  | Big_rebase_detected
  | Failed_to_load_should_retry
  | Failed_to_load_should_abort
  | Server_non_opt_build_mode
[@@deriving show, enum]

let (_ignored : t -> int) = to_enum

exception Exit_with of t

let exit_code = function
  | Interrupted -> -6
  | No_error -> 0
  | Kill_error -> 1 (* used in clientStop/Start/Restart *)
  | Server_shutting_down_due_to_sigusr2 -> 1 (* used in server *)
  (* CARE! exit code 2 is also used when an ocaml binary exits
  with an unhandled exception. It's a shame that we can't distinguish
  such exits from the following two codes. *)
  | Type_error -> 2 (* used in clientCheck *)
  | Uncaught_exception -> 221
  | Hhconfig_changed -> 4
  | Unused_server -> 5
  | No_server_running_should_retry ->
    6 (* gen by clientConnect, read by find_hh.sh *)
  | Server_hung_up_should_retry ->
    6 (* gen by clientConnect, read by find_hh.sh *)
  | Out_of_time -> 7
  | Out_of_retries -> 7
  | Checkpoint_error -> 8
  | Build_id_mismatch -> 9
  | Monitor_connection_failure -> 9
  | Input_error -> 10
  | Lock_stolen -> 11
  | Lost_parent_monitor -> 12
  | Shared_mem_assertion_failure -> 14
  | Out_of_shared_memory -> 15
  | Hash_table_full -> 16
  | Heap_full -> 17
  | Worker_oomed -> 30
  | Worker_busy -> 31
  | Worker_not_found_exception -> 32
  | Worker_failed_to_send_job -> 33
  | Server_already_exists -> 77
  | Missing_hhi -> 97
  | Socket_error -> 98
  | Dfind_died -> 99
  | Dfind_unresponsive -> 100
  | EventLogger_Timeout -> 101
  | CantRunAI -> 102
  | Watchman_failed -> 103
  | Hhconfig_deleted -> 104
  | EventLogger_broken_pipe -> 106
  | Redecl_heap_overflow -> 107
  | EventLogger_restart_out_of_retries -> 108
  | Watchman_fresh_instance -> 109
  | Watchman_invalid_result -> 110
  | Big_rebase_detected -> 111
  | IDE_malformed_request -> 201
  | IDE_no_server -> 202
  | IDE_out_of_retries -> 203
  | Nfs_root -> 204
  | IDE_init_failure -> 205
  | IDE_typechecker_died -> 206
  | IDE_new_client_connected -> 207
  | Lazy_decl_bug -> 208
  | Decl_heap_elems_bug -> 209
  | Parser_heap_build_error -> 210
  | File_provider_stale -> 211
  | Sql_assertion_failure -> 212
  | Local_type_env_stale -> 213
  | Sql_cantopen -> 214
  | Sql_corrupt -> 215
  | Sql_misuse -> 216
  | Decl_not_found -> 217
  | Failed_to_load_should_retry ->
    218 (* gen by serverInit, read by serverMonitor+clientConnect *)
  | Failed_to_load_should_abort ->
    219 (* gen by serverInit, read by serverMonitor+clientConnect *)
  | Server_hung_up_should_abort ->
    (* generated by clientConnect, read by find_hh.sh *)
    220
  | Server_non_opt_build_mode -> 222

let exit_code_to_string (code : int) : string =
  let rec f acc candidate_i =
    match of_enum candidate_i with
    | Some candidate when exit_code candidate = code ->
      f (show candidate :: acc) (candidate_i + 1)
    | _ when candidate_i > max ->
      (* If an ocaml binary exits with an uncaught exception, it produces exit code 2.
      We'll reconstruct that fact here. However our binaries should avoid exiting
      in this manner, since exit code 2 also means "hh_check completed successfully"! *)
      if code = 2 then
        "Uncaught_exception_ocaml" :: acc
      else
        acc
    | _ -> f acc (candidate_i + 1)
  in
  match f [] min with
  | [] -> "?"
  | candidates -> String.concat "/" candidates

let unpack = function
  | Unix.WEXITED n -> ("exit", n)
  | Unix.WSIGNALED n ->
    (*
     * Ocaml signal numbers are mapped from System signal numbers.
     * They are negative.
     * See caml_convert_signal_number byterun/signals.c in Ocaml system source code
     * to convert from Ocaml number to System number
     *)
    ("signaled", n)
  | Unix.WSTOPPED n -> ("stopped", n)
