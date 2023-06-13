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

void miniis_destroy(miniis_handle_t* handle) {
  mis_system_destroy(handle->sys_);
  free(handle);
}
