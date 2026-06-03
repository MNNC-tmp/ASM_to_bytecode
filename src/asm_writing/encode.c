/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** encode
*/

#include <unistd.h>
#include "writes.h"

int emit_byte(int fd, unsigned char b)
{
    if (write(fd, &b, 1) != 1)
        return -1;
    return 0;
}

int emit_u16(int fd, unsigned short v)
{
    unsigned char b[2] = {v & 0xFF, (v >> 8) & 0xFF};

    if (write(fd, b, 2) != 2)
        return -1;
    return 0;
}

int emit_u32(int fd, unsigned int v)
{
    unsigned char b[4] = {
        v & 0xFF, (v >> 8) & 0xFF, (v >> 16) & 0xFF, (v >> 24) & 0xFF
    };

    if (write(fd, b, 4) != 4)
        return -1;
    return 0;
}

int emit_u64(int fd, unsigned long long v)
{
    unsigned char b[8];
    int i = 0;

    while (i < 8) {
        b[i] = (v >> (i * 8)) & 0xFF;
        i++;
    }
    if (write(fd, b, 8) != 8)
        return -1;
    return 0;
}
