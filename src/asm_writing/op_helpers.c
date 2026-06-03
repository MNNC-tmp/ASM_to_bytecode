/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** op_helpers
*/

#include "writes.h"

int arith_rr(int fd, int dst, int src, unsigned char op)
{
    if (emit_byte(fd, make_rex(1, src >= 8, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, op) < 0)
        return -1;
    return emit_byte(fd, make_modrm(src & 7, dst & 7));
}

int arith_ri(int fd, int dst, long imm, int sub)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x81) < 0)
        return -1;
    if (emit_byte(fd, make_modrm(sub, dst & 7)) < 0)
        return -1;
    return emit_u32(fd, (unsigned int)imm);
}

int rm_single(int fd, int r, unsigned char op, int sub)
{
    if (emit_byte(fd, make_rex(1, 0, r >= 8)) < 0)
        return -1;
    if (emit_byte(fd, op) < 0)
        return -1;
    return emit_byte(fd, make_modrm(sub, r & 7));
}

int jcc(int fd, unsigned char op, long off)
{
    if (emit_byte(fd, 0x0F) < 0)
        return -1;
    if (emit_byte(fd, op) < 0)
        return -1;
    return emit_u32(fd, (unsigned int)off);
}

int setcc(int fd, unsigned char op, int r)
{
    if (emit_byte(fd, 0x0F) < 0)
        return -1;
    if (emit_byte(fd, op) < 0)
        return -1;
    return emit_byte(fd, make_modrm(0, r & 7));
}
