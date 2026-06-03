/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** program
*/

#ifndef PROGRAM_H_
    #define PROGRAM_H_
    #include <stddef.h>
    #include <stdbool.h>

    #define DEFAULT_OUTPUT "program.out"

typedef enum {
    SUCCESS,
    PRS_ERROR, // Parser error
    BC_ERR, // Binary creation error
    RW_ERR // Read/Write error
} status_codes_t;

typedef struct output_params {
    char *name;
    char *file;
} output_params_t;

typedef void(apply_flag_t)(output_params_t *, char *, size_t *);
typedef struct handle_flag {
    char *flag;
    apply_flag_t *apply;
} handle_flags_t;

// Flags handler
void handle_h(output_params_t *params, char *arg, size_t *offset);
void handle_o(output_params_t *output_params, char *arg, size_t *offset);

// Flags handler
extern const handle_flags_t flags[];

// Main functions
int parser(output_params_t *params, char **args, int *err);
int compile(output_params_t *params);
#endif /* !PROGRAM_H_ */
