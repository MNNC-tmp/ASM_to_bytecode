/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_cmp
*/

#include "writes.h"

int write_cmp(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int src = reg_id(args[2]);

    if (dst < 0)
        return -1;
    if (src >= 0)
        return arith_rr(fd, dst, src, 0x39);
    return arith_ri(fd, dst, parse_imm(args[2]), 7);
}
