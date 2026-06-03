/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** writes
*/

#ifndef WRITES_H_
    #define WRITES_H_
    #include <stddef.h>
    #include <stdbool.h>

    #define MAGIC_NBR "\x7f\x45\x4c\x46"

typedef enum {
    MOV,
    ADD,

} design_patterns_t;

typedef int (*op_write_t)(int, char **args);
typedef struct keywords {
    char *name;
    design_patterns_t pattern;
    op_write_t apply_fnc;
} keywords_t;

typedef struct elf_header {
    char magic_nbr[4];
    char type[1];
    char endianness[1];
    char elf_version[1];
    char abi[1];
    char padding[8];
    char exec_type[2];
    char exec_machine[2];
    char exec_version[4];
    char exec_entry[8];
    char exec_phoff[8];
    char exec_shoff[8];
    char exec_flags[4];
    char exec_ehsize[2];
    char exec_phentsize[2];
    char exec_phnum[2];
    char exec_shentsize[2];
    char exec_shnum[2];
    char exec_shstrndx[2];
} elf_header_t;

#endif /* !WRITES_H_ */
