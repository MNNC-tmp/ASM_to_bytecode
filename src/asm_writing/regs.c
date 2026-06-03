/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** regs
*/

#include <string.h>
#include "writes.h"

struct reg_s {
    const char *name;
    int id;
    int size;
};

static const struct reg_s reg_table[] = {
    {"rax", 0, 64},
    {"rcx", 1, 64},
    {"rdx", 2, 64},
    {"rbx", 3, 64},
    {"rsp", 4, 64},
    {"rbp", 5, 64},
    {"rsi", 6, 64},
    {"rdi", 7, 64},
    {"r8", 8, 64},
    {"r9", 9, 64},
    {"r10", 10, 64},
    {"r11", 11, 64},
    {"r12", 12, 64},
    {"r13", 13, 64},
    {"r14", 14, 64},
    {"r15", 15, 64},
    {"eax", 0, 32},
    {"ecx", 1, 32},
    {"edx", 2, 32},
    {"ebx", 3, 32},
    {"esp", 4, 32},
    {"ebp", 5, 32},
    {"esi", 6, 32},
    {"edi", 7, 32},
    {"r8d", 8, 32},
    {"r9d", 9, 32},
    {"r10d", 10, 32},
    {"r11d", 11, 32},
    {"r12d", 12, 32},
    {"r13d", 13, 32},
    {"r14d", 14, 32},
    {"r15d", 15, 32},
    {"ax", 0, 16},
    {"cx", 1, 16},
    {"dx", 2, 16},
    {"bx", 3, 16},
    {"sp", 4, 16},
    {"bp", 5, 16},
    {"si", 6, 16},
    {"di", 7, 16},
    {"r8w", 8, 16},
    {"r9w", 9, 16},
    {"r10w", 10, 16},
    {"r11w", 11, 16},
    {"r12w", 12, 16},
    {"r13w", 13, 16},
    {"r14w", 14, 16},
    {"r15w", 15, 16},
    {"al", 0, 8},
    {"cl", 1, 8},
    {"dl", 2, 8},
    {"bl", 3, 8},
    {"spl", 4, 8},
    {"bpl", 5, 8},
    {"sil", 6, 8},
    {"dil", 7, 8},
    {"r8b", 8, 8},
    {"r9b", 9, 8},
    {"r10b", 10, 8},
    {"r11b", 11, 8},
    {"r12b", 12, 8},
    {"r13b", 13, 8},
    {"r14b", 14, 8},
    {"r15b", 15, 8},
    {"ah", 4, 8},
    {"ch", 5, 8},
    {"dh", 6, 8},
    {"bh", 7, 8},
    {NULL, -1, 0}
};

static const struct reg_s *find_reg(const char *name)
{
    for (int i = 0; reg_table[i].name; i++)
        if (strcmp(reg_table[i].name, name) == 0)
            return &reg_table[i];
    return NULL;
}

int reg_id(const char *name)
{
    const struct reg_s *r = find_reg(name);

    return r ? r->id : -1;
}

int reg_size(const char *name)
{
    const struct reg_s *r = find_reg(name);

    return r ? r->size : -1;
}
