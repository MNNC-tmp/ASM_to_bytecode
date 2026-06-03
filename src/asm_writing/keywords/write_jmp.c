/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jmp
*/

#include "writes.h"

int write_jmp(int fd, char **args)
{
    long off = parse_imm(args[1]);

    if (emit_byte(fd, 0xE9) < 0)
        return -1;
    return emit_u32(fd, (unsigned int)off);
}
