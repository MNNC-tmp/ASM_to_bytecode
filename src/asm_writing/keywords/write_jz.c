/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jz
*/

#include "writes.h"

int write_jz(int fd, char **args)
{
    return jcc(fd, 0x84, parse_imm(args[1]));
}
