/**
 * Project: Mini-is
 * File: integration_test/src/main.cc
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

#include "mini-is/mini-is.h"

void assert_memory_all_zero(miniis_handle_t* handle) {
  char buffer[1];
  for (int i = 0; i < MIS_MEMORY_SIZE; i++) {
    miniis_read_memory(handle, i, 1, buffer);
    EXPECT_EQ(buffer[0], 0x00);
  }
}

TEST(IntegrationTest, NoOp) {
  miniis_handle_t* handle = miniis_init();
  ASSERT_NE(handle, nullptr);

  miniis_execute_instruction(handle, "NOP");
  char buffer[1];
  miniis_read_memory(handle, 0, 1, buffer);
  assert_memory_all_zero(handle);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
