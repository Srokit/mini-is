/**
 * Project: Mini-is
 * File: src/system.c
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

#include "mini-is/system.h"

#include <stdlib.h>

mis_system_t* mis_system_create(void) {
    mis_system_t* system = malloc(sizeof(mis_system_t));
    system->memory_ = mis_memory_create();
    return system;
}

void mis_system_destroy(mis_system_t* system) {
    mis_memory_destroy(system->memory_);
    free(system);
}
