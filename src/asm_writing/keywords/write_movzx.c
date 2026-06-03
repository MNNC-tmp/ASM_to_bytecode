/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_movzx
*/

#include "writes.h"

int write_movzx(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int src = reg_id(args[2]);
    unsigned char op2 = reg_size(args[2]) == 8 ? 0xB6 : 0xB7;

    if (dst < 0 || src < 0)
        return -1;
    if (emit_byte(fd, make_rex(1, dst >= 8, src >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x0F) < 0)
        return -1;
    if (emit_byte(fd, op2) < 0)
        return -1;
    return emit_byte(fd, make_modrm(dst & 7, src & 7));
}
