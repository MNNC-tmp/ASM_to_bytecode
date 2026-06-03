/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_lods
*/

#include "writes.h"
int write_lods(int fd, char **args)
{
    (void)args;
    if (emit_byte(fd, 0x48) < 0)
        return -1;
    return emit_byte(fd, 0xAD);
}
