/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_xchg
*/

#include "writes.h"

int write_xchg(int fd, char **args)
{
    int r1 = reg_id(args[1]);
    int r2 = reg_id(args[2]);

    if (r1 < 0 || r2 < 0)
        return -1;
    if (emit_byte(fd, make_rex(1, r2 >= 8, r1 >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x87) < 0)
        return -1;
    return emit_byte(fd, make_modrm(r2 & 7, r1 & 7));
}
