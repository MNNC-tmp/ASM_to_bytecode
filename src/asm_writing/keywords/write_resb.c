/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_resb
*/

#include "writes.h"

int write_resb(int fd, char **args)
{
    long n = parse_imm(args[1]);

    for (long i = 0; i < n; i++) {
        if (emit_byte(fd, 0) < 0)
            return -1;
    }
    return 0;
}
