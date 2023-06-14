/**
 * Project: Mini-is
 * File: test/src/system_test.cc
 * Author:  Stanley Rokita <stan@stansa.dev>
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

#include "mini-is/system.h"

class SystemTest : public ::testing::Test {
 protected:
  void SetUp() override {
    system_ = mis_system_create();
    ASSERT_NE(system_, nullptr);
  }

  void TearDown() override {
    mis_system_destroy(system_);
  }
  mis_system_t* system_;
};

TEST_F(SystemTest, SystemInit) {
  EXPECT_NE(system_, nullptr);
}

TEST_F(SystemTest, AllRegsStartAsZero) {
  for (int i = 0; i < MIS_NUM_REGISTERS; i++) {
    EXPECT_EQ(mis_system_read_register(system_, i), 0x00);
  }
}
