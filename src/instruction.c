/**
 * Project: Mini-is
 * File: src/instruction.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/instruction.h"

#include <string.h>

mis_ins_t mis_ins_from_str(const char* ins_str) {
  mis_ins_t ins;
  memset(&ins, 0, sizeof(mis_ins_t));

  if (strcmp(ins_str, "NOP") == 0) {
    ins.op_ = MIS_INS_OP_NOP;
  }

  return ins;
}
