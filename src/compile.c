/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** compile
*/

#include "program.h"
#include "writes.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static int find_keyword(char **tokens)
{
    char buf[64];

    for (int i = 0; i < NB_KEYWORDS; i++)
        if (strcmp(keywords[i].name, tokens[0]) == 0)
            return i;
    if (!tokens[1])
        return -1;
    snprintf(buf, sizeof(buf), "%s %s", tokens[0], tokens[1]);
    for (int i = 0; i < NB_KEYWORDS; i++)
        if (strcmp(keywords[i].name, buf) == 0)
            return i;
    return -1;
}

static int dispatch_tokens(int fd, char **tokens)
{
    int idx = find_keyword(tokens);

    if (idx < 0 || !keywords[idx].apply_fnc)
        return 0;
    return keywords[idx].apply_fnc(fd, tokens);
}

static int process_line(int fd, char *line)
{
    char **tokens;
    int ret = 0;

    clean_line(line);
    tokens = split_line(line, ' ');
    if (!tokens || !tokens[0]) {
        free_split(tokens);
        return 0;
    }
    if (tokens[0][strlen(tokens[0]) - 1] != ':')
        ret = dispatch_tokens(fd, tokens);
    free_split(tokens);
    return ret;
}

static int process_asm(int fd, FILE *src)
{
    char line[512];

    while (fgets(line, sizeof(line), src)) {
        if (process_line(fd, line) < 0)
            return BC_ERR;
    }
    return SUCCESS;
}

static int open_output(const char *name)
{
    int fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0755);

    if (fd < 0)
        return -1;
    if (write_headers(fd) < 0) {
        close(fd);
        return -1;
    }
    return fd;
}

int compile(output_params_t *params)
{
    int fd = open_output(params->name);
    FILE *src;
    int ret;

    if (fd < 0)
        return RW_ERR;
    src = fopen(params->file, "r");
    if (!src) {
        close(fd);
        return RW_ERR;
    }
    ret = process_asm(fd, src);
    fclose(src);
    close(fd);
    return ret;
}
