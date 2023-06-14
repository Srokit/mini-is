/**
 * Project: Mini-is
 * File: inc/mini-is/system.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

/**
 * The struct which contains all the system wide data that
 * must be passed around.
 */

#include "mini-is/memory.h"
// For MIS_NUM_REGISTERS
#include "mini-is/mini-is.h"

#ifndef MINI_IS_SYSTEM_H
#define MINI_IS_SYSTEM_H

typedef int mis_register_t;

typedef struct mis_system_struct {
  mis_memory_t* memory_;
  mis_register_t registers_[MIS_NUM_REGISTERS];
} mis_system_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Read memory buffer in system offset at `read_start_address` bytes
 * with size `size` into `dst_buffer`.
 */
void mis_system_read_memory(mis_system_t*,
                            int /* read_start_address */,
                            int /* size */,
                            char* /* dst_buffer */);

/**
 * Write into system memory buffer offset at `write_start_address` bytes
 * with size `size` from `src_buffer`.
 */
void mis_system_write_memory(mis_system_t*,
                             int /* write_start_address */,
                             int /* size */,
                             const char* /* src_buffer */);

/**
 * Get the value of the system register at `reg_num`.
 */
mis_register_t mis_system_read_register(mis_system_t*, int /* reg_num */);

mis_system_t* mis_system_create(void);
void mis_system_destroy(mis_system_t*);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MINI_IS_SYSTEM_H
