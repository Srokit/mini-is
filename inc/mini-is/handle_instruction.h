/**
 * Project: Mini-is
 * File: inc/mini-is/instruction.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

/**
 * Code that handles instructions.
 */

#ifndef MINI_IS_HANDLE_INSTRUCTION_H
#define MINI_IS_HANDLE_INSTRUCTION_H

#include "mini-is/instruction.h"
#include "mini-is/system.h"

#ifdef __cplusplus
extern "C" {
#endif

void mis_handle_instruction(mis_system_t*, mis_ins_t*);

#ifdef __cplusplus
}
#endif

#endif  // MINI_IS_HANDLE_INSTRUCTION_H
