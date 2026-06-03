/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_sar
*/

#include "writes.h"
#include <string.h>

int write_sar(int fd, char **args)
{
    int dst = reg_id(args[1]);

    if (dst < 0)
        return -1;
    if (strcmp(args[2], "cl") == 0)
        return shift_cl(fd, dst, 7);
    return shift_imm(fd, dst, (int)parse_imm(args[2]), 7);
}
