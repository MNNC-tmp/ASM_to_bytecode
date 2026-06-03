/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_call
*/

#include "writes.h"

int write_call(int fd, char **args)
{
    long off = parse_imm(args[1]);

    if (emit_byte(fd, 0xE8) < 0)
        return -1;
    return emit_u32(fd, (unsigned int)off);
}
