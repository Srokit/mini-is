/**
 * Project: Mini-is
 * File: src/instruction.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/handle_instruction.h"

void mis_handle_instruction(mis_ins_t* ins) {
  switch (ins->op) {
    case MIS_INS_OP_NOP:
      // Do nothing
      break;
  }
}
