/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_je
*/

#include "writes.h"

int write_je(int fd, char **args)
{
    return jcc(fd, 0x84, parse_imm(args[1]));
}
