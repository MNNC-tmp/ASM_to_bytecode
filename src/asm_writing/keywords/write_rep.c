/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_rep
*/

#include "writes.h"
int write_rep(int fd, char **args)
{
    (void)args;
    return emit_byte(fd, 0xF3);
}
