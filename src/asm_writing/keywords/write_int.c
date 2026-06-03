/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_int
*/

#include "writes.h"

int write_int(int fd, char **args)
{
    long n = parse_imm(args[1]);

    if (n == 3)
        return emit_byte(fd, 0xCC);
    if (emit_byte(fd, 0xCD) < 0)
        return -1;
    return emit_byte(fd, (unsigned char)n);
}
