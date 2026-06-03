/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_stos
*/

#include "writes.h"
int write_stos(int fd, char **args)
{
    (void)args;
    if (emit_byte(fd, 0x48) < 0)
        return -1;
    return emit_byte(fd, 0xAB);
}
