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

// Constants used globally
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

/**
 * Initialize the internal mini-is system and return a handle which must be
 * passed to all other API functions.
 */
miniis_handle_t* miniis_init(void);

/**
 * Destroy the internal mini-is system and free the memory associated with
 * it. Must be called after `miniis_init`. All other API functions will
 * be invalid after this is called on the used handle.
 */
void miniis_deinit(miniis_handle_t*);

/**
 * Execute an instruction string on the mini-is system. See "INSTUCTION_SET.txt"
 * for the available instructions and their formats.
 */
void miniis_execute_instruction(miniis_handle_t*, const char*);

/**
 * Read from mini-is memory buffer offset at `read_start_address` bytes
 * with size `size` into `dst_buffer`.
 */
void miniis_read_memory(miniis_handle_t*,
                        int /* read_start_address */,
                        int /* size */,
                        char* /* dst_buffer */);

/**
 * Return the value of the system register at `reg_num`.
 */
int miniis_read_register(miniis_handle_t*, int /* reg_num */);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MINI_IS_H
