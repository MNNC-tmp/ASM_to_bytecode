/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** main
*/
#include "program.h"

int main(int ac, char **av)
{
    output_params_t params = {0};
    int errno = SUCCESS;

    (void)ac;
    if (parser(&params, &av[1], &errno))
        return errno;
    return compile(&params);
}
