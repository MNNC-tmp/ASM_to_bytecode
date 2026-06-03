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
    /* Data movement */
    MOV, MOVZX, MOVSX, LEA, PUSH, POP, XCHG, CMOV,
    /* Arithmetic */
    ADD, SUB, INC, DEC, NEG, IMUL, MUL, IDIV, DIV,
    /* Bitwise and shift */
    AND, OR, XOR, NOT, SHL, SHR, SAR, ROL, ROR, BSWAP,
    /* Comparison and flags */
    CMP, TEST, SETE, SETNE, SETL, SETG, SETLE, SETGE,
    /* Jumps */
    JMP,
    JE, JZ, JNE, JNZ,
    JL, JNGE, JG, JNLE, JLE, JNG, JGE, JNL,
    JB, JNAE, JA, JNBE,
    JS, JNS, JO, JNO,
    /* Function calls and returns */
    CALL, RET, LEAVE, ENTER,
    /* Memory and string operations */
    MOVS, STOS, LODS, SCAS, CMPS,
    REP, REPE, REPZ, REPNE, REPNZ,
    /* System and control */
    SYSCALL, INT, NOP, HLT, CPUID, RDTSC,
    /* NASM assembler directives */
    SECTION_TEXT, SECTION_DATA, SECTION_BSS,
    GLOBAL, EXTERN,
    DB, DW, DD, DQ, RESB,
    EQU, DEFINE, TIMES,
    KEYWORDS_COUNT,
} design_patterns_t;

    #define NB_KEYWORDS KEYWORDS_COUNT

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

// Keywords table
extern const keywords_t keywords[];

// Data movement
int write_mov(int fd, char **args);
int write_movzx(int fd, char **args);
int write_movsx(int fd, char **args);
int write_lea(int fd, char **args);
int write_push(int fd, char **args);
int write_pop(int fd, char **args);
int write_xchg(int fd, char **args);
int write_cmov(int fd, char **args);

// Arithmetic
int write_add(int fd, char **args);
int write_sub(int fd, char **args);
int write_inc(int fd, char **args);
int write_dec(int fd, char **args);
int write_neg(int fd, char **args);
int write_imul(int fd, char **args);
int write_mul(int fd, char **args);
int write_idiv(int fd, char **args);
int write_div(int fd, char **args);

// Bitwise and shift
int write_and(int fd, char **args);
int write_or(int fd, char **args);
int write_xor(int fd, char **args);
int write_not(int fd, char **args);
int write_shl(int fd, char **args);
int write_shr(int fd, char **args);
int write_sar(int fd, char **args);
int write_rol(int fd, char **args);
int write_ror(int fd, char **args);
int write_bswap(int fd, char **args);

// Comparison and flags
int write_cmp(int fd, char **args);
int write_test(int fd, char **args);
int write_sete(int fd, char **args);
int write_setne(int fd, char **args);
int write_setl(int fd, char **args);
int write_setg(int fd, char **args);
int write_setle(int fd, char **args);
int write_setge(int fd, char **args);

// Jumps
int write_jmp(int fd, char **args);
int write_je(int fd, char **args);
int write_jz(int fd, char **args);
int write_jne(int fd, char **args);
int write_jnz(int fd, char **args);
int write_jl(int fd, char **args);
int write_jnge(int fd, char **args);
int write_jg(int fd, char **args);
int write_jnle(int fd, char **args);
int write_jle(int fd, char **args);
int write_jng(int fd, char **args);
int write_jge(int fd, char **args);
int write_jnl(int fd, char **args);
int write_jb(int fd, char **args);
int write_jnae(int fd, char **args);
int write_ja(int fd, char **args);
int write_jnbe(int fd, char **args);
int write_js(int fd, char **args);
int write_jns(int fd, char **args);
int write_jo(int fd, char **args);
int write_jno(int fd, char **args);

// Function calls and returns
int write_call(int fd, char **args);
int write_ret(int fd, char **args);
int write_leave(int fd, char **args);
int write_enter(int fd, char **args);

// Memory and string operations
int write_movs(int fd, char **args);
int write_stos(int fd, char **args);
int write_lods(int fd, char **args);
int write_scas(int fd, char **args);
int write_cmps(int fd, char **args);
int write_rep(int fd, char **args);
int write_repe(int fd, char **args);
int write_repz(int fd, char **args);
int write_repne(int fd, char **args);
int write_repnz(int fd, char **args);

// System and control
int write_syscall(int fd, char **args);
int write_int(int fd, char **args);
int write_nop(int fd, char **args);
int write_hlt(int fd, char **args);
int write_cpuid(int fd, char **args);
int write_rdtsc(int fd, char **args);

// NASM assembler directives
int write_section_text(int fd, char **args);
int write_section_data(int fd, char **args);
int write_section_bss(int fd, char **args);
int write_global(int fd, char **args);
int write_extern(int fd, char **args);
int write_db(int fd, char **args);
int write_dw(int fd, char **args);
int write_dd(int fd, char **args);
int write_dq(int fd, char **args);
int write_resb(int fd, char **args);
int write_equ(int fd, char **args);
int write_define(int fd, char **args);
int write_times(int fd, char **args);

// Shared instruction helpers
int arith_rr(int fd, int dst, int src, unsigned char op);
int arith_ri(int fd, int dst, long imm, int sub);
int rm_single(int fd, int r, unsigned char op, int sub);
int jcc(int fd, unsigned char op, long off);
int setcc(int fd, unsigned char op, int r);
int shift_cl(int fd, int dst, int sub);
int shift_imm(int fd, int dst, int imm, int sub);

// Utils
char **split_line(const char *str, char sep);
void free_split(char **tokens);
void clean_line(char *line);
long parse_imm(const char *s);

// ELF output
int write_headers(int fd);

// Encoding primitives
int emit_byte(int fd, unsigned char b);
int emit_u16(int fd, unsigned short v);
int emit_u32(int fd, unsigned int v);
int emit_u64(int fd, unsigned long long v);
unsigned char make_rex(int w, int r, int b_flag);
unsigned char make_modrm(int reg, int rm);

// Register lookup
int reg_id(const char *name);
int reg_size(const char *name);

#endif /* !WRITES_H_ */
