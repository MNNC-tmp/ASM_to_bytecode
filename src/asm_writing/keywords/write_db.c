/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_db
*/

#include "writes.h"

int write_db(int fd, char **args)
{
    int i = 1;

    while (args[i]) {
        if (emit_byte(fd, (unsigned char)parse_imm(args[i])) < 0)
            return -1;
        i++;
    }
    return 0;
}
