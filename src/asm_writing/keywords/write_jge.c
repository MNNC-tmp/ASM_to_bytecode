/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jge
*/

#include "writes.h"

int write_jge(int fd, char **args)
{
    return jcc(fd, 0x8D, parse_imm(args[1]));
}
