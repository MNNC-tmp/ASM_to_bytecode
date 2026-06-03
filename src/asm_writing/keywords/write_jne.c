/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jne
*/

#include "writes.h"

int write_jne(int fd, char **args)
{
    return jcc(fd, 0x85, parse_imm(args[1]));
}
