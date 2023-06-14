/**
 * Project: Mini-is
 * File: inc/mini-is/memory.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

/**
 * `mis_memory` represents RAM for the system.
 */

#ifndef MINI_IS_MEMORY_H
#define MINI_IS_MEMORY_H

typedef unsigned char mis_byte_t;

typedef struct {
  mis_byte_t* bytes_;
} mis_memory_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get a pointer to the byte at `mem_offset`.
 */
mis_byte_t* mis_memory_get(mis_memory_t*, int /* mem_offset */);

/**
 * Read `size` bytes from memory buffer offset at `read_start_address` bytes
 * into `dst_buffer`.
 */
void mis_memory_read(mis_memory_t*,
                     int /* read_start_address */,
                     int /* size */,
                     char* /* dst_buffer */);

/**
 * Write `size` bytes from `src_buffer` into memory buffer offset at
 * `write_start_address` bytes.
 */
void mis_memory_write(mis_memory_t*,
                      int /* write_start_address */,
                      int /* size */,
                      const char* /* src_buffer */);

mis_memory_t* mis_memory_create(void);
void mis_memory_destroy(mis_memory_t*);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MINI_IS_MEMORY_H
