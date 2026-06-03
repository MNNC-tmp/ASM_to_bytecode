/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** shift_helpers
*/

#include "writes.h"

int shift_cl(int fd, int dst, int sub)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0xD3) < 0)
        return -1;
    return emit_byte(fd, make_modrm(sub, dst & 7));
}

int shift_imm(int fd, int dst, int imm, int sub)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0xC1) < 0)
        return -1;
    if (emit_byte(fd, make_modrm(sub, dst & 7)) < 0)
        return -1;
    return emit_byte(fd, imm & 0xFF);
}
