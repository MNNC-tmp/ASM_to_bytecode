/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_bswap
*/

#include "writes.h"

int write_bswap(int fd, char **args)
{
    int r = reg_id(args[1]);

    if (r < 0)
        return -1;
    if (emit_byte(fd, make_rex(1, 0, r >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x0F) < 0)
        return -1;
    return emit_byte(fd, 0xC8 + (r & 7));
}
