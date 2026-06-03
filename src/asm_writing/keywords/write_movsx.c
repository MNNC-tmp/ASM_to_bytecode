/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_movsx
*/

#include "writes.h"

static int movsx_byte_word(int fd, int dst, int src, int sz)
{
    unsigned char op2 = sz == 8 ? 0xBE : 0xBF;

    if (emit_byte(fd, make_rex(1, dst >= 8, src >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x0F) < 0)
        return -1;
    if (emit_byte(fd, op2) < 0)
        return -1;
    return emit_byte(fd, make_modrm(dst & 7, src & 7));
}

static int movsx_dword(int fd, int dst, int src)
{
    if (emit_byte(fd, make_rex(1, dst >= 8, src >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x63) < 0)
        return -1;
    return emit_byte(fd, make_modrm(dst & 7, src & 7));
}

int write_movsx(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int src = reg_id(args[2]);
    int sz = reg_size(args[2]);

    if (dst < 0 || src < 0)
        return -1;
    if (sz == 32)
        return movsx_dword(fd, dst, src);
    return movsx_byte_word(fd, dst, src, sz);
}
