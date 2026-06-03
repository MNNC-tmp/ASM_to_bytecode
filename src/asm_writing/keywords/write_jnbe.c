/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jnbe
*/

#include "writes.h"

int write_jnbe(int fd, char **args)
{
    return jcc(fd, 0x87, parse_imm(args[1]));
}
