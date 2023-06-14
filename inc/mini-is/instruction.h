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

typedef enum {
  MIS_INS_OP_NOP,
  MIS_INS_OP_LOAD,
  MIS_INS_OP_STORE_CONST,
} mis_ins_op_t;

// Will be expanded later
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

mis_ins_t mis_ins_from_str(const char* str);

#endif  // MINI_IS_INSTRUCTION_H
