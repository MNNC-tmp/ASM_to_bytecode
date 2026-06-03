/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_lea
*/

#include "writes.h"
#include <string.h>

static int parse_mem_base(const char *expr)
{
    char buf[32];
    int i = 0;
    const char *p = expr + 1;

    while (*p && *p != '+' && *p != '-' && *p != ']' && *p != '*' && i < 31) {
        buf[i] = *p;
        i++;
        p++;
    }
    buf[i] = '\0';
    return reg_id(buf);
}

int write_lea(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int base = parse_mem_base(args[2]);

    if (dst < 0 || base < 0)
        return -1;
    if (emit_byte(fd, make_rex(1, dst >= 8, base >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x8D) < 0)
        return -1;
    return emit_byte(fd, make_modrm(dst & 7, base & 7));
}
