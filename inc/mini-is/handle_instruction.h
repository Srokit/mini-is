/**
 * Project: Mini-is
 * File: inc/mini-is/instruction.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#ifndef MINI_IS_HANDLE_INSTRUCTION_H
#define MINI_IS_HANDLE_INSTRUCTION_H

#include "mini-is/instruction.h"
#include "mini-is/system.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Handle an instruction. Will perform the necessary changes to `system`
 * according to the operation type of `instruction`.
 */
void mis_handle_instruction(
    mis_system_t* /* system */, mis_ins_t* /* instruction */);

#ifdef __cplusplus
}
#endif

#endif  // MINI_IS_HANDLE_INSTRUCTION_H
