/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_jno
*/

#include "writes.h"

int write_jno(int fd, char **args)
{
    return jcc(fd, 0x81, parse_imm(args[1]));
}
