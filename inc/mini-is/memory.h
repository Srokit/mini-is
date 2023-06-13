/**
 * Project: Mini-is
 * File: inc/mini-is/memory.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

/**
 * `mis_memory` represents RAM for the system.
 * Use `mis_memory_get` to get a pointer to a certain byte.
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

mis_memory_t* mis_memory_create(void);

void mis_memory_destroy(mis_memory_t*);

mis_byte_t* mis_memory_get(mis_memory_t*, int);

void mis_memory_read(mis_memory_t*,
                     int /* read_start_address */,
                     int /* size */,
                     char* /* dst_buffer */);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MINI_IS_MEMORY_H
