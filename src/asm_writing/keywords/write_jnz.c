/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jnz
*/

#include "writes.h"

int write_jnz(int fd, char **args)
{
    return jcc(fd, 0x85, parse_imm(args[1]));
}
