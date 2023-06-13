/**
 * Project: Mini-is
 * File: src/memory.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/memory.h"

#include <stdlib.h>

mis_memory_t* mis_memory_create(void) {
  return (mis_memory_t*) malloc(sizeof(mis_memory_t));
}

void mis_memory_destroy(mis_memory_t* memory) {
  free(memory);
}
