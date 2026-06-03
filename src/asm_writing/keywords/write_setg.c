/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_setg
*/

#include "writes.h"

int write_setg(int fd, char **args)
{
    int r = reg_id(args[1]);

    if (r < 0)
        return -1;
    return setcc(fd, 0x9F, r);
}
