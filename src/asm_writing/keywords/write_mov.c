/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_mov
*/

#include "writes.h"

static int mov_rr(int fd, int dst, int src)
{
    if (emit_byte(fd, make_rex(1, src >= 8, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x89) < 0)
        return -1;
    return emit_byte(fd, make_modrm(src & 7, dst & 7));
}

static int mov_ri32(int fd, int dst, unsigned int imm)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0xC7) < 0)
        return -1;
    if (emit_byte(fd, make_modrm(0, dst & 7)) < 0)
        return -1;
    return emit_u32(fd, imm);
}

static int mov_ri64(int fd, int dst, long long imm)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0xB8 + (dst & 7)) < 0)
        return -1;
    return emit_u64(fd, (unsigned long long)imm);
}

int write_mov(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int src = reg_id(args[2]);
    long imm;

    if (dst < 0)
        return -1;
    if (src >= 0)
        return mov_rr(fd, dst, src);
    imm = parse_imm(args[2]);
    if (imm >= 0 && imm <= 0xFFFFFFFFL)
        return mov_ri32(fd, dst, (unsigned int)imm);
    return mov_ri64(fd, dst, (long long)imm);
}
