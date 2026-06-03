/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** program
*/

#ifndef PROGRAM_H_
    #define PROGRAM_H_

typedef enum {
    SUCCESS,
    PRS_ERROR, // Parser error
    BC_ERR, // Binary creation error
    RW_ERR // Read/Write error
} status_codes_t;

typedef struct output_params {
    char *name;
} output_params_t;

typedef void(*apply_flag_t)(output_params_t *, char *);
typedef struct handle_flag {
    char *flag;
    apply_flag_t *apply;
} handle_flags_t;

#endif /* !PROGRAM_H_ */
