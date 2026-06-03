/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_test
*/

#include "writes.h"

static int test_rr(int fd, int dst, int src)
{
    if (emit_byte(fd, make_rex(1, src >= 8, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x85) < 0)
        return -1;
    return emit_byte(fd, make_modrm(src & 7, dst & 7));
}

static int test_ri(int fd, int dst, long imm)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0xF7) < 0)
        return -1;
    if (emit_byte(fd, make_modrm(0, dst & 7)) < 0)
        return -1;
    return emit_u32(fd, (unsigned int)imm);
}

int write_test(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int src = reg_id(args[2]);

    if (dst < 0)
        return -1;
    if (src >= 0)
        return test_rr(fd, dst, src);
    return test_ri(fd, dst, parse_imm(args[2]));
}
