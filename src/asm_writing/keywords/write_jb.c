/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jb
*/

#include "writes.h"

int write_jb(int fd, char **args)
{
    return jcc(fd, 0x82, parse_imm(args[1]));
}
