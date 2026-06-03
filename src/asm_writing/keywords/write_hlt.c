/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_hlt
*/

#include "writes.h"
int write_hlt(int fd, char **args)
{
    (void)args;
    return emit_byte(fd, 0xF4);
}
