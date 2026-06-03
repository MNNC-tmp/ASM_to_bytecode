/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jnae
*/

#include "writes.h"

int write_jnae(int fd, char **args)
{
    return jcc(fd, 0x82, parse_imm(args[1]));
}
