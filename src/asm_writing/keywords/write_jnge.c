/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jnge
*/

#include "writes.h"

int write_jnge(int fd, char **args)
{
    return jcc(fd, 0x8C, parse_imm(args[1]));
}
