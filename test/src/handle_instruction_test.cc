/**
 * Project: Mini-is
 * File: test/src/handle_instruction_test.cc
 * Author:  Stanley Rokita <stan@stansa.dev>
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

#include "mini-is/handle_instruction.h"

class HandleInstructionTest : public ::testing::Test {
 protected:
  void SetUp() override {
    sys_ = mis_system_create();
    ASSERT_NE(sys_, nullptr);
  }

  void TearDown() override {
    mis_system_destroy(sys_);
  }
  mis_system_t* sys_;
};

// Helper functions
void assert_memory_is_zero(mis_memory_t*);

TEST_F(HandleInstructionTest, SimpleNoOp) {
  mis_ins_t ins;
  ins.op_ = MIS_INS_OP_NOP;
  mis_handle_instruction(sys_, &ins);

  // Memory should be the same as before
  assert_memory_is_zero(sys_->memory_);
}

// Helper functions impl
void assert_memory_is_zero(mis_memory_t* memory) {
  for (int i = 0; i < MIS_MEMORY_SIZE; i++) {
    EXPECT_EQ(*mis_memory_get(memory, i), 0);
  }
}
