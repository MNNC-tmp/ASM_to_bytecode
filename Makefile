##
## EPITECH PROJECT, 2026
## G-PSU-200-MPL-2-1-minishell1-6
## File description:
## Makefile
##

CC			=	epiclang

INCLUDE		=	-I./include/

CFLAGS		=	-Wall -Wextra $(INCLUDE)

LIB	=	./lib/libmy.a

SRCF		=	src/
KWDIR		=	$(SRCF)asm_writing/keywords/
SRC			=	$(SRCF)flags.c	\
				$(SRCF)headers.c	\
				$(SRCF)parser.c		\
				$(SRCF)compile.c	\
				$(SRCF)asm_writing/fill_header.c	\
				$(SRCF)asm_writing/keywords_table.c	\
				$(SRCF)asm_writing/utils.c	\
				$(SRCF)asm_writing/encode.c	\
				$(SRCF)asm_writing/rex_modrm.c	\
				$(SRCF)asm_writing/regs.c	\
				$(SRCF)asm_writing/op_helpers.c	\
				$(SRCF)asm_writing/shift_helpers.c	\
				$(KWDIR)write_add.c	\
				$(KWDIR)write_and.c	\
				$(KWDIR)write_bswap.c	\
				$(KWDIR)write_call.c	\
				$(KWDIR)write_cmov.c	\
				$(KWDIR)write_cmp.c	\
				$(KWDIR)write_cmps.c	\
				$(KWDIR)write_cpuid.c	\
				$(KWDIR)write_db.c	\
				$(KWDIR)write_dd.c	\
				$(KWDIR)write_dec.c	\
				$(KWDIR)write_define.c	\
				$(KWDIR)write_div.c	\
				$(KWDIR)write_dq.c	\
				$(KWDIR)write_dw.c	\
				$(KWDIR)write_enter.c	\
				$(KWDIR)write_equ.c	\
				$(KWDIR)write_extern.c	\
				$(KWDIR)write_global.c	\
				$(KWDIR)write_hlt.c	\
				$(KWDIR)write_idiv.c	\
				$(KWDIR)write_imul.c	\
				$(KWDIR)write_inc.c	\
				$(KWDIR)write_int.c	\
				$(KWDIR)write_ja.c	\
				$(KWDIR)write_jb.c	\
				$(KWDIR)write_je.c	\
				$(KWDIR)write_jg.c	\
				$(KWDIR)write_jge.c	\
				$(KWDIR)write_jl.c	\
				$(KWDIR)write_jle.c	\
				$(KWDIR)write_jmp.c	\
				$(KWDIR)write_jnae.c	\
				$(KWDIR)write_jnbe.c	\
				$(KWDIR)write_jne.c	\
				$(KWDIR)write_jng.c	\
				$(KWDIR)write_jnge.c	\
				$(KWDIR)write_jnl.c	\
				$(KWDIR)write_jnle.c	\
				$(KWDIR)write_jno.c	\
				$(KWDIR)write_jns.c	\
				$(KWDIR)write_jnz.c	\
				$(KWDIR)write_jo.c	\
				$(KWDIR)write_js.c	\
				$(KWDIR)write_jz.c	\
				$(KWDIR)write_lea.c	\
				$(KWDIR)write_leave.c	\
				$(KWDIR)write_lods.c	\
				$(KWDIR)write_mov.c	\
				$(KWDIR)write_movs.c	\
				$(KWDIR)write_movsx.c	\
				$(KWDIR)write_movzx.c	\
				$(KWDIR)write_mul.c	\
				$(KWDIR)write_neg.c	\
				$(KWDIR)write_nop.c	\
				$(KWDIR)write_not.c	\
				$(KWDIR)write_or.c	\
				$(KWDIR)write_pop.c	\
				$(KWDIR)write_push.c	\
				$(KWDIR)write_rdtsc.c	\
				$(KWDIR)write_rep.c	\
				$(KWDIR)write_repe.c	\
				$(KWDIR)write_repne.c	\
				$(KWDIR)write_repnz.c	\
				$(KWDIR)write_repz.c	\
				$(KWDIR)write_resb.c	\
				$(KWDIR)write_ret.c	\
				$(KWDIR)write_rol.c	\
				$(KWDIR)write_ror.c	\
				$(KWDIR)write_sar.c	\
				$(KWDIR)write_scas.c	\
				$(KWDIR)write_section_bss.c	\
				$(KWDIR)write_section_data.c	\
				$(KWDIR)write_section_text.c	\
				$(KWDIR)write_sete.c	\
				$(KWDIR)write_setg.c	\
				$(KWDIR)write_setge.c	\
				$(KWDIR)write_setl.c	\
				$(KWDIR)write_setle.c	\
				$(KWDIR)write_setne.c	\
				$(KWDIR)write_shl.c	\
				$(KWDIR)write_shr.c	\
				$(KWDIR)write_stos.c	\
				$(KWDIR)write_sub.c	\
				$(KWDIR)write_syscall.c	\
				$(KWDIR)write_test.c	\
				$(KWDIR)write_times.c	\
				$(KWDIR)write_xchg.c	\
				$(KWDIR)write_xor.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	./compile

MAIN		=	$(SRCF)main.c		\

TEST_FILES	=	tests/tests.c		\

TEST_BIN	=	./unit_tests
TEST_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(MAIN) $(CFLAGS) -o $(NAME)

%o:			%.c
	$(CC) $(LIB) -o $< -c $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

unit_tests:
	clang $(TEST_FILES) $(SRC) $(INCLUDE) $(TEST_FLAGS) -o $(TEST_BIN)

tests_run:	unit_tests
	$(TEST_BIN)

tests_clean: 
	rm -f ./unit_tests*
	$(RM) *.html
	$(RM) *.css

coverage: tests_clean
	gcc $(TEST_FILES) $(SRC) $(INCLUDE) $(TEST_FLAGS) -o $(TEST_BIN)
	$(TEST_BIN)
	gcovr --html --html-details -o coverage.html

tests_re: tests_clean tests_run
