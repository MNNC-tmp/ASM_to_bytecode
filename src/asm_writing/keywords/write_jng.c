/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jng
*/

#include "writes.h"

int write_jng(int fd, char **args)
{
    return jcc(fd, 0x8E, parse_imm(args[1]));
}
