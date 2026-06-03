/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** flags
*/

#include "program.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

const handle_flags_t flags[] = {
    {"-o", handle_o},
    {"-h", handle_h},
    {"--help", handle_h},
    {NULL, NULL}
};

void handle_h(output_params_t *params, char *arg, size_t *offset)
{
    (void)params;
    (void)arg;
    (void)offset;
    if (printf("%s\n", "USAGE : ./compile [-flag [...]] <file>\n"
            "\tFLAGS :\n\t-o [name] : set the outputs to \"name\"\n\t-h "
            ": display help message") < 0)
        exit(PRS_ERROR);
    exit(SUCCESS);
}

void handle_o(output_params_t *output_params, char *arg, size_t *offset)
{
    if (!arg || !output_params || !offset)
        return;
    output_params->name = strdup(arg);
    *offset += 1;
    return;
}
