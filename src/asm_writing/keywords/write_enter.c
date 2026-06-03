/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_enter
*/

#include "writes.h"

int write_enter(int fd, char **args)
{
    long frame = parse_imm(args[1]);
    long level = args[2] ? parse_imm(args[2]) : 0;

    if (emit_byte(fd, 0xC8) < 0)
        return -1;
    if (emit_u16(fd, (unsigned short)frame) < 0)
        return -1;
    return emit_byte(fd, (unsigned char)level);
}
