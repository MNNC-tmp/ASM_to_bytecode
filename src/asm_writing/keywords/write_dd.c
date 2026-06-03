/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_dd
*/

#include "writes.h"

int write_dd(int fd, char **args)
{
    int i = 1;

    while (args[i]) {
        if (emit_u32(fd, (unsigned int)parse_imm(args[i])) < 0)
            return -1;
        i++;
    }
    return 0;
}
