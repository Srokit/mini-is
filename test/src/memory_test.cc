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

TEST_F(MemoryTest, MemoryRead) {
  mis_byte_t* byte_ptr = mis_memory_get(memory_, 5);
  *byte_ptr = 0x42;
  char buffer[1];
  mis_memory_read(memory_, 5, 1, buffer);
  EXPECT_EQ(buffer[0], 0x42);
}

TEST_F(MemoryTest, MemoryWrite) {
  char buffer[] = {0x42};
  mis_memory_write(memory_, 5, 1, buffer);
  mis_byte_t* byte_ptr = mis_memory_get(memory_, 5);
  EXPECT_EQ(*byte_ptr, 0x42);

  // Write multiple bytes
  char buffer2[] = {0x42, 0x43, 0x44};
  mis_memory_write(memory_, 5, 3, buffer2);
  EXPECT_EQ(*byte_ptr, 0x42);
  byte_ptr = mis_memory_get(memory_, 6);
  EXPECT_EQ(*byte_ptr, 0x43);
  byte_ptr = mis_memory_get(memory_, 7);
  EXPECT_EQ(*byte_ptr, 0x44);
}
