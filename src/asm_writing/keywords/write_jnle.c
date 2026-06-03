/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jnle
*/

#include "writes.h"

int write_jnle(int fd, char **args)
{
    return jcc(fd, 0x8F, parse_imm(args[1]));
}
