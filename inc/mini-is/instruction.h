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
} mis_ins_op_t;

// Will be expanded later
typedef struct {
  mis_ins_op_t op_;
} mis_ins_t;

#endif  // MINI_IS_INSTRUCTION_H
