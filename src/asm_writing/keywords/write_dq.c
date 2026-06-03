/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_dq
*/

#include "writes.h"

int write_dq(int fd, char **args)
{
    int i = 1;

    while (args[i]) {
        if (emit_u64(fd, (unsigned long long)parse_imm(args[i])) < 0)
            return -1;
        i++;
    }
    return 0;
}
