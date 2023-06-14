/**
 * Project: Mini-is
 * File: src/mini-is.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/mini-is.h"

#include <stdlib.h>

#include "mini-is/handle_instruction.h"
#include "mini-is/instruction.h"
#include "mini-is/system.h"

miniis_handle_t* miniis_init(void) {
  miniis_handle_t* handle = malloc(sizeof(miniis_handle_t));
  handle->sys_ = mis_system_create();
  return handle;
}

void miniis_execute_instruction(miniis_handle_t* handle, const char* ins_str) {
  mis_ins_t ins = mis_ins_from_str(ins_str);
  mis_handle_instruction(handle->sys_, &ins);
}

void miniis_read_memory(miniis_handle_t* handle,
                        int read_start_address,
                        int size,
                        char* dst_buffer) {
  mis_system_read_memory(handle->sys_,
                         read_start_address,
                         size,
                         dst_buffer);
}

int miniis_read_register(miniis_handle_t* handle, int reg_num) {
  return (int) mis_system_read_register(handle->sys_, reg_num);
}

void miniis_destroy(miniis_handle_t* handle) {
  mis_system_destroy(handle->sys_);
  free(handle);
}
