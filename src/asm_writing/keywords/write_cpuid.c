/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_cpuid
*/

#include "writes.h"
int write_cpuid(int fd, char **args)
{
    (void)args;
    if (emit_byte(fd, 0x0F) < 0)
        return -1;
    return emit_byte(fd, 0xA2);
}
