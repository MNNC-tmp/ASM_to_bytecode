/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_setl
*/

#include "writes.h"

int write_setl(int fd, char **args)
{
    int r = reg_id(args[1]);

    if (r < 0)
        return -1;
    return setcc(fd, 0x9C, r);
}
