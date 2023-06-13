/**
 * Project: Mini-is
 * File: src/memory.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/memory.h"

// For MIS_MEMORY_SIZE
#include "mini-is/mini-is.h"

#include <stdlib.h>
#include <string.h>

mis_memory_t* mis_memory_create(void) {
  mis_memory_t* memory = (mis_memory_t*) malloc(sizeof(mis_memory_t));
  memory->bytes_ = (mis_byte_t*) malloc(MIS_MEMORY_SIZE * sizeof(mis_byte_t));
  memset(memory->bytes_, 0, MIS_MEMORY_SIZE);
  return memory;
}

void mis_memory_destroy(mis_memory_t* memory) {
  free(memory->bytes_);
  free(memory);
}

mis_byte_t* mis_memory_get(mis_memory_t* memory, int byte_offsest) {
  return memory->bytes_ + byte_offsest;
}

void mis_memory_read(mis_memory_t* memory,
                     int read_start_address,
                     int size,
                     char* dst_buffer) {
  memcpy(dst_buffer,
         memory->bytes_ + read_start_address,
         size);
}
