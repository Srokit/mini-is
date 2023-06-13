/**
 * Project: Mini-is
 * File: integration_test/src/main.cc
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

#include "mini-is/mini-is.h"

TEST(IntegrationTest, NoOp) {
  miniis_handle_t* handle = miniis_init();
  ASSERT_NE(handle, nullptr);

  miniis_execute_instruction(handle, "NOP");

  // TODO: Assert memory is the same as before
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
