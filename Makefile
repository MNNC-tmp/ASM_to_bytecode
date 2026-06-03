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
SRC			=	$(SRCF)flags.c	\
				$(SRCF)headers.c	\
				$(SRCF)parser.c		\

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
