/**
 * Project: Mini-is
 * File: src/instruction.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/instruction.h"

#include <stdlib.h>
#include <string.h>

#define MIS_INS_FIRST_WORD_BUFF_SIZE 5

#define MIS_INS_LOAD_STR_REG_START 5
#define MIS_INS_LOAD_STR_REG_SIZE 1
#define MIS_INS_LOAD_STR_MEM_OFFSET_START 7
#define MIS_INS_STORECONST_STR_MEM_OFFSET_START 11

int find_word_end(const char*, int);
const char* get_dyalloced_substr(const char*, int /* start */, int /* size */);

mis_ins_t _ins_from_load_str(const char*);
mis_ins_t _ins_from_store_const(const char*);

mis_ins_t mis_ins_from_str(const char* ins_str) {
  mis_ins_t ins;
  memset(&ins, 0, sizeof(mis_ins_t));

  int first_word_end = find_word_end(ins_str, 0);

  // TODO(Stan): Handle case where first word is longer than max chars
  const char* first_word = get_dyalloced_substr(ins_str, 0, first_word_end);

  if (strcmp(ins_str, "NOP") == 0) {
    ins.op_ = MIS_INS_OP_NOP;
  } else if (strcmp(first_word, "LOAD") == 0) {
    return _ins_from_load_str(ins_str);
  } else if (strcmp(first_word, "STORECONST") == 0) {
    return _ins_from_store_const(ins_str);
  }

  free((void*) first_word);

  return ins;
}

int find_word_end(const char* ins_str, int start) {
  int i = start;
  while (ins_str[i] != ' ' && ins_str[i] != '\0') {
    i++;
  }
  return i;
}

const char* get_dyalloced_substr(const char* str, int start, int size) {
  char* substr = (char*) malloc(size + 1);
  strncpy(substr, &str[start], size);
  substr[size] = '\0';
  return substr;
}

mis_ins_t _ins_from_load_str(const char* ins_str) {
  mis_ins_t ins;
  memset(&ins, 0, sizeof(mis_ins_t));

  const char* reg_num_str = get_dyalloced_substr(ins_str,
                                                 MIS_INS_LOAD_STR_REG_START,
                                                 MIS_INS_LOAD_STR_REG_SIZE);

  int ins_str_after_mem = strlen(ins_str) - MIS_INS_LOAD_STR_MEM_OFFSET_START;
  const char* mem_offset_str = get_dyalloced_substr(
      ins_str, MIS_INS_LOAD_STR_MEM_OFFSET_START, ins_str_after_mem);

  ins.op_ = MIS_INS_OP_LOAD;
  ins.load_reg_ = atoi(reg_num_str);
  ins.load_mem_offset_ = atoi(mem_offset_str);

  free((void*) reg_num_str);
  free((void*) mem_offset_str);

  return ins;
}

mis_ins_t _ins_from_store_const(const char* ins_str) {
  mis_ins_t ins;
  memset(&ins, 0, sizeof(mis_ins_t));

  int mem_offset_word_end = find_word_end(ins_str, MIS_INS_STORECONST_STR_MEM_OFFSET_START);
  int mem_offset_size = mem_offset_word_end - MIS_INS_STORECONST_STR_MEM_OFFSET_START;
  const char* mem_offset_str = get_dyalloced_substr(
      ins_str,  MIS_INS_STORECONST_STR_MEM_OFFSET_START, mem_offset_size);

  int ins_str_after_mem = strlen(ins_str) - (mem_offset_word_end + 1);
  const char* const_val_str = get_dyalloced_substr(
      ins_str,  mem_offset_word_end + 1, ins_str_after_mem);

  ins.op_ = MIS_INS_OP_STORE_CONST;
  ins.store_const_mem_offset_ = atoi(mem_offset_str);
  ins.store_const_value_ = atoi(const_val_str);

  free((void*) mem_offset_str);
  free((void*) const_val_str);

  return ins;
}
