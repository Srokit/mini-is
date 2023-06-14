/**
 * Project: Mini-is
 * File: src/instruction.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/handle_instruction.h"

#include <stdio.h>

static void _mis_handle_load(mis_system_t*, mis_ins_t*);
static void _mis_handle_store_const(mis_system_t*, mis_ins_t*);

void mis_handle_instruction(mis_system_t* sys, mis_ins_t* ins) {
  switch (ins->op_) {
    case MIS_INS_OP_NOP:
      // Do nothing
      break;
    case MIS_INS_OP_LOAD:
      _mis_handle_load(sys, ins);
      break;
    case MIS_INS_OP_STORE_CONST:
      // Store constant value into memory
      _mis_handle_store_const(sys, ins);
      break;
    default:
      printf("Unknown instruction op: %d\n", ins->op_);
      break;
  }
}

static void _mis_handle_load(mis_system_t* sys, mis_ins_t* ins) {
  // Load value from memory into register
  int sizeof_reg = sizeof(mis_register_t) / sizeof(mis_byte_t);
  mis_system_read_memory(sys,
                          ins->load_mem_offset_ * sizeof_reg,
                          sizeof_reg,
                          (char*) &(sys->registers_[ins->load_reg_]));
}

static void _mis_handle_store_const(mis_system_t* sys, mis_ins_t* ins) {
  // Store const value into memory
  int sizeof_reg = sizeof(mis_register_t) / sizeof(mis_byte_t);
  mis_system_write_memory(sys,
                          ins->store_const_mem_offset_ * sizeof_reg,
                          sizeof_reg,
                          (char*) &(ins->store_const_value_));
}
