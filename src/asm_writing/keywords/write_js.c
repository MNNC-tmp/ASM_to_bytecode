/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_js
*/

#include "writes.h"

int write_js(int fd, char **args)
{
    return jcc(fd, 0x88, parse_imm(args[1]));
}
