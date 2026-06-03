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

void handle_h(output_params_t *params, char *arg)
{
    (void)params;
    (void)arg;
    if (printf("%s\n", "USAGE : ./compile [-flag [...]] <file>\n"
            "\t FLAGS :") < 0)
        exit(PRS_ERROR);
    exit(SUCCESS);
}
