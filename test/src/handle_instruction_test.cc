/**
 * Project: Mini-is
 * File: test/src/handle_instruction_test.cc
 * Author:  Stanley Rokita <stan@stansa.dev>
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

#include "mini-is/handle_instruction.h"

TEST(HandleInstructionTest, SimpleNoOp) {
  mis_ins_t ins;
  ins.op = MIS_INS_OP_NOP;
  mis_handle_instruction(&ins);

  // TODO(Stan): Check that nothing in system has changed
}
