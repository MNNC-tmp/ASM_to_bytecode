/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_imul
*/

#include "writes.h"

static int imul_rr(int fd, int dst, int src)
{
    if (emit_byte(fd, make_rex(1, dst >= 8, src >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x0F) < 0)
        return -1;
    if (emit_byte(fd, 0xAF) < 0)
        return -1;
    return emit_byte(fd, make_modrm(dst & 7, src & 7));
}

static int imul_rri(int fd, int dst, int src, long imm)
{
    if (emit_byte(fd, make_rex(1, dst >= 8, src >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x69) < 0)
        return -1;
    if (emit_byte(fd, make_modrm(dst & 7, src & 7)) < 0)
        return -1;
    return emit_u32(fd, (unsigned int)imm);
}

int write_imul(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int src = reg_id(args[2]);

    if (dst < 0 || src < 0)
        return -1;
    if (!args[3])
        return imul_rr(fd, dst, src);
    return imul_rri(fd, dst, src, parse_imm(args[3]));
}
