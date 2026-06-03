/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jo
*/

#include "writes.h"

int write_jo(int fd, char **args)
{
    return jcc(fd, 0x80, parse_imm(args[1]));
}
