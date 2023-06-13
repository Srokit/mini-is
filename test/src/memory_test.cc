/**
 * Project: Mini-is
 * File: test/src/memory_test.cc
 * Author:  Stanley Rokita <stan@stansa.dev>
 * Copyright: Unlicensed
 */

#include <gtest/gtest.h>

// extern "C" {
#include "mini-is/memory.h"
// }

TEST(MemoryTest, MemoryInit) {
    mis_memory_t* memory = mis_memory_create();
    EXPECT_NE(memory, nullptr);
    if (memory != nullptr)
        mis_memory_destroy(memory);
}
