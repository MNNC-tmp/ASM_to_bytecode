/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_leave
*/

#include "writes.h"
int write_leave(int fd, char **args)
{
    (void)args;
    return emit_byte(fd, 0xC9);
}
