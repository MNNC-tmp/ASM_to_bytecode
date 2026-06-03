/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** rex_modrm
*/

#include "writes.h"

unsigned char make_rex(int w, int r, int b_flag)
{
    return (unsigned char)(0x40 | (w ? 8 : 0) | (r ? 4 : 0) | (b_flag ? 1 : 0));
}

unsigned char make_modrm(int reg, int rm)
{
    return (unsigned char)(0xC0 | ((reg & 7) << 3) | (rm & 7));
}
