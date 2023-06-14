/**
 * Project: Mini-is
 * File: src/system.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/system.h"

#include <stdlib.h>
#include <string.h>

mis_system_t* mis_system_create(void) {
    mis_system_t* system = malloc(sizeof(mis_system_t));
    system->memory_ = mis_memory_create();
    memset((void*) system->registers_, 0,
           MIS_NUM_REGISTERS * sizeof(mis_register_t));
    return system;
}

void mis_system_destroy(mis_system_t* system) {
    mis_memory_destroy(system->memory_);
    free(system);
}

void mis_system_read_memory(mis_system_t* system,
                            int read_start_address,
                            int size,
                            char* dst_buffer) {
    mis_memory_read(system->memory_,
                    read_start_address,
                    size,
                    dst_buffer);
}

void mis_system_write_memory(mis_system_t* system,
                             int write_start_address,
                             int size,
                             const char* src_buffer) {
    mis_memory_write(system->memory_,
                     write_start_address,
                     size,
                     src_buffer);
}

mis_register_t mis_system_read_register(mis_system_t* sys, int reg_num) {
    return sys->registers_[reg_num];
}
