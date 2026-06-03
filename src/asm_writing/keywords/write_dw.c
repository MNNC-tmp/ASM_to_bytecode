/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_dw
*/

#include "writes.h"

int write_dw(int fd, char **args)
{
    int i = 1;

    while (args[i]) {
        if (emit_u16(fd, (unsigned short)parse_imm(args[i])) < 0)
            return -1;
        i++;
    }
    return 0;
}
