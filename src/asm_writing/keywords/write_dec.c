/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_dec
*/

#include "writes.h"
#include <string.h>

int write_dec(int fd, char **args)
{
    int r = reg_id(args[1]);

    if (r < 0)
        return -1;
    return rm_single(fd, r, 0xFF, 1);
}
