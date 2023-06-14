/**
 * Project: Mini-is
 * File: pub_inc/mini-is/mini-is.h
 * Author:  Stan Rokita <stan@stansa.dev>
 * Date: 2023-06-13
 * Copyright: Unlicensed
 */

/**
 * Public API for mini-is
 */

#ifndef MINI_IS_H
#define MINI_IS_H

// Memory size in bytes
#define MIS_MEMORY_SIZE 65536  // 2^16 B

#define MIS_NUM_REGISTERS 8

// Forward declare bc the system struct is private
typedef struct mis_system_struct mis_system_t;

typedef struct {
  mis_system_t* sys_;
} miniis_handle_t;

#ifdef __cplusplus
extern "C" {
#endif

miniis_handle_t* miniis_init(void);

void miniis_execute_instruction(miniis_handle_t*, const char*);

void miniis_read_memory(miniis_handle_t*,
                        int /* read_start_address */,
                        int /* size */,
                        char* /* dst_buffer */);

int miniis_read_register(miniis_handle_t*, int);

void miniis_destroy(miniis_handle_t*);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MINI_IS_H
