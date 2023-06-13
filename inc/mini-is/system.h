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

#ifndef MINI_IS_SYSTEM_H
#define MINI_IS_SYSTEM_H

typedef struct mis_system_struct {
  mis_memory_t* memory_;
} mis_system_t;

#ifdef __cplusplus
extern "C" {
#endif

mis_system_t* mis_system_create(void);

void mis_system_destroy(mis_system_t*);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MINI_IS_SYSTEM_H
