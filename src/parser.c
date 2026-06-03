/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** parser
*/

#include "program.h"
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

static int is_valid_file(char *path)
{
    struct stat s = {0};

    if (!path)
        return 0;
    if (stat(path, &s) < 0)
        return 0;
    return 1;
}

static int set_ptr_return(int return_val, int *ptr)
{
    if (ptr)
        *ptr = return_val;
    return return_val;
}

static int handle_flag(output_params_t *params, char **args, size_t *ptr)
{
    if (!params || !args || !ptr)
        return 0;
    for (int i = 0; flags[i].flag; i++) {
        if (!strcmp(args[0], flags[i].flag)) {
            flags[i].apply(params, args[1], ptr);
            return 1;
        }
    }
    return 0;
}

int parser(output_params_t *params, char **args, int *err)
{
    if (!params || !args)
        return set_ptr_return(PRS_ERROR, err);
    for (size_t i = 0; args[i]; i++) {
        if (handle_flag(params, &args[i], &i))
            continue;
        if (is_valid_file(args[i])) {
            params->file = strdup(args[i]);
            break;
        }
    }
    if (!params->file)
        return set_ptr_return(PRS_ERROR, err);
    if (!params->name)
        params->name = strdup(DEFAULT_OUTPUT);
    return SUCCESS;
}
