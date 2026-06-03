/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** write_mov
*/

#include "writes.h"
#include <stdlib.h>

static int is_mem(const char *s)
{
    return s && s[0] == '[';
}

static int mem_base(const char *s)
{
    char buf[16];
    int i = 0;
    const char *p = s + 1;

    while (*p && *p != '+' && *p != '-' && *p != ']' && i < 15) {
        buf[i] = *p;
        i++;
        p++;
    }
    buf[i] = '\0';
    return reg_id(buf);
}

static long mem_disp(const char *s)
{
    const char *p = s + 1;

    while (*p && *p != '+' && *p != '-' && *p != ']')
        p++;
    if (*p == '+' || *p == '-')
        return strtol(p, NULL, 0);
    return 0;
}

static int calc_mod(long disp, int base)
{
    if (disp == 0 && base != 5)
        return 0x00;
    if (disp >= -128 && disp <= 127)
        return 0x40;
    return 0x80;
}

static int mov_mem_store(int fd, const char *dst, int src)
{
    int base = mem_base(dst);
    long disp = mem_disp(dst);
    int mod = calc_mod(disp, base);

    if (base < 0 || src < 0)
        return 0;
    if (emit_byte(fd, make_rex(1, src >= 8, base >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x89) < 0)
        return -1;
    if (emit_byte(fd, mod | ((src & 7) << 3) | (base & 7)) < 0)
        return -1;
    if (mod == 0x40)
        return emit_byte(fd, (unsigned char)(char)disp);
    if (mod == 0x80)
        return emit_u32(fd, (unsigned int)(int)disp);
    return 0;
}

static int mov_mem_load(int fd, int dst, const char *src)
{
    int base = mem_base(src);
    long disp = mem_disp(src);
    int mod = calc_mod(disp, base);

    if (base < 0)
        return 0;
    if (emit_byte(fd, make_rex(1, dst >= 8, base >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x8B) < 0)
        return -1;
    if (emit_byte(fd, mod | ((dst & 7) << 3) | (base & 7)) < 0)
        return -1;
    if (mod == 0x40)
        return emit_byte(fd, (unsigned char)(char)disp);
    if (mod == 0x80)
        return emit_u32(fd, (unsigned int)(int)disp);
    return 0;
}

static int mov_rr(int fd, int dst, int src)
{
    if (emit_byte(fd, make_rex(1, src >= 8, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0x89) < 0)
        return -1;
    return emit_byte(fd, make_modrm(src & 7, dst & 7));
}

static int mov_ri32(int fd, int dst, unsigned int imm)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0xC7) < 0)
        return -1;
    if (emit_byte(fd, make_modrm(0, dst & 7)) < 0)
        return -1;
    return emit_u32(fd, imm);
}

static int mov_ri64(int fd, int dst, long long imm)
{
    if (emit_byte(fd, make_rex(1, 0, dst >= 8)) < 0)
        return -1;
    if (emit_byte(fd, 0xB8 + (dst & 7)) < 0)
        return -1;
    return emit_u64(fd, (unsigned long long)imm);
}

int write_mov(int fd, char **args)
{
    int dst = reg_id(args[1]);
    int src = reg_id(args[2]);
    long imm;

    if (is_mem(args[1]))
        return mov_mem_store(fd, args[1], src);
    if (dst < 0)
        return -1;
    if (is_mem(args[2]))
        return mov_mem_load(fd, dst, args[2]);
    if (src >= 0)
        return mov_rr(fd, dst, src);
    imm = parse_imm(args[2]);
    if (imm >= 0 && imm <= 0xFFFFFFFFL)
        return mov_ri32(fd, dst, (unsigned int)imm);
    return mov_ri64(fd, dst, (long long)imm);
}
