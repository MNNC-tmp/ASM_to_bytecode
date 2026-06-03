/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jns
*/

#include "writes.h"

int write_jns(int fd, char **args)
{
    return jcc(fd, 0x89, parse_imm(args[1]));
}
