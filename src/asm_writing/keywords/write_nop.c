/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_nop
*/

#include "writes.h"
int write_nop(int fd, char **args)
{
    (void)args;
    return emit_byte(fd, 0x90);
}
