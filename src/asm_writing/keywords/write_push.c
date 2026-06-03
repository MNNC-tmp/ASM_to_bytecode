/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_push
*/

#include "writes.h"

int write_push(int fd, char **args)
{
    int r = reg_id(args[1]);

    if (r < 0)
        return -1;
    if (r >= 8 && emit_byte(fd, 0x41) < 0)
        return -1;
    return emit_byte(fd, 0x50 + (r & 7));
}
