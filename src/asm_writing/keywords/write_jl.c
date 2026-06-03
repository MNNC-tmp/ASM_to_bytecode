/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jl
*/

#include "writes.h"

int write_jl(int fd, char **args)
{
    return jcc(fd, 0x8C, parse_imm(args[1]));
}
