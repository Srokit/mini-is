/**
 * Project: Mini-is
 * File: integration_test/src/main.cc
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

#include "mini-is/mini-is.h"

class IntegrationTest : public ::testing::Test {
 protected:
  void SetUp() override {
    handle_ = miniis_init();
    ASSERT_NE(handle_, nullptr);
  }

  void TearDown() override {
    miniis_deinit(handle_);
  }
  miniis_handle_t* handle_;
};

void assert_memory_all_zero(miniis_handle_t* handle) {
  char buffer[1];
  for (int i = 0; i < MIS_MEMORY_SIZE; i++) {
    miniis_read_memory(handle, i, 1, buffer);
    EXPECT_EQ(buffer[0], 0x00);
  }
}

TEST_F(IntegrationTest, NoOp) {
  miniis_execute_instruction(handle_, "NOP");
  char buffer[1];
  miniis_read_memory(handle_, 0, 1, buffer);
  assert_memory_all_zero(handle_);
}

TEST_F(IntegrationTest, LoadConstIntoMemAndLoadIntoReg) {
  miniis_execute_instruction(handle_, "STORECONST 55 1");
  miniis_execute_instruction(handle_, "LOAD 0 55");
  EXPECT_EQ(miniis_read_register(handle_, 0), 1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
