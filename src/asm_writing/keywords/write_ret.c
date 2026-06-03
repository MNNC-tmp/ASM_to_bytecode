/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_ret
*/

#include "writes.h"

int write_ret(int fd, char **args)
{
    if (!args[1])
        return emit_byte(fd, 0xC3);
    if (emit_byte(fd, 0xC2) < 0)
        return -1;
    return emit_u16(fd, (unsigned short)parse_imm(args[1]));
}
