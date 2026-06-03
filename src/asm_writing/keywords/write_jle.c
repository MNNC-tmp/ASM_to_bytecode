/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jle
*/

#include "writes.h"

int write_jle(int fd, char **args)
{
    return jcc(fd, 0x8E, parse_imm(args[1]));
}
