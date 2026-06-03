/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jnl
*/

#include "writes.h"

int write_jnl(int fd, char **args)
{
    return jcc(fd, 0x8D, parse_imm(args[1]));
}
