/**
 * Project: Mini-is
 * File: inc/mini-is/instruction.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

/**
 * Contains instruction parsing code.
 */

#ifndef MINI_IS_INSTRUCTION_H
#define MINI_IS_INSTRUCTION_H

/**
 * The instruction opcodes which align with the instructions listed in
 * "INSTRUCTION_SET.txt"
 */
typedef enum {
  MIS_INS_OP_NOP,
  MIS_INS_OP_LOAD,
  MIS_INS_OP_STORE_CONST,
} mis_ins_op_t;

/**
 * Represents a single instruction. Holds the op type as well as the parameters
 * needed for each instruction. View "INSTRUCTION_SET.txt" for more info on
 * params.
 */
typedef struct {
  mis_ins_op_t op_;
  // Unions values differ based on op_
  union {
    struct {
      int load_reg_;
      int load_mem_offset_;
    };
    struct {
      int store_const_mem_offset_;
      int store_const_value_;
    };
  };
} mis_ins_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Parses a string into an instruction object.
 */
// TODO(Stan): Handle errors on invalid instruction strings
mis_ins_t mis_ins_from_str(const char* /* str */);

#ifdef __cplusplus
}
#endif

#endif  // MINI_IS_INSTRUCTION_H
