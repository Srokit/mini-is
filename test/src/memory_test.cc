/**
 * Project: Mini-is
 * File: test/src/memory_test.cc
 * Author:  Stanley Rokita <stan@stansa.dev>
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

#include "mini-is/memory.h"

class MemoryTest : public ::testing::Test {
 protected:
  void SetUp() override {
    memory_ = mis_memory_create();
    ASSERT_NE(memory_, nullptr);
  }

  void TearDown() override {
    mis_memory_destroy(memory_);
  }
  mis_memory_t* memory_;
};

TEST_F(MemoryTest, MemoryInit) {
  EXPECT_NE(memory_, nullptr);
}

TEST_F(MemoryTest, MemoryGetRandom) {
  mis_byte_t* byte_ptr = mis_memory_get(memory_, 5);

  EXPECT_NE(byte_ptr, nullptr);
  EXPECT_EQ(*byte_ptr, 0);
}
