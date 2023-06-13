/**
 * Project: Mini-is
 * File: inc/mini-is/memory.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#ifndef MINI_IS_MEMORY_H
#define MINI_IS_MEMORY_H

typedef struct {
  int placeholder;
} mis_memory_t;

#ifdef __cplusplus
extern "C" {
#endif

mis_memory_t* mis_memory_create(void);

void mis_memory_destroy(mis_memory_t*);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MINI_IS_MEMORY_H
