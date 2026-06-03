/*
** EPITECH PROJECT, 2026
** ASM_to_bytecode
** File description:
** utils
*/

#include <stdlib.h>
#include <string.h>

long parse_imm(const char *s)
{
    return strtol(s, NULL, 0);
}

void free_split(char **tokens)
{
    if (!tokens)
        return;
    for (int i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}

void clean_line(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == ';' || line[i] == '\n' || line[i] == '\r') {
            line[i] = '\0';
            return;
        }
        if (line[i] == ',')
            line[i] = ' ';
    }
}

static void free_tokens(char **tokens, int count)
{
    for (int i = 0; i < count; i++)
        free(tokens[i]);
    free(tokens);
}

static char *make_token(const char *start, const char *end)
{
    size_t len = end - start;
    char *token = malloc(len + 1);

    if (!token)
        return NULL;
    memcpy(token, start, len);
    token[len] = '\0';
    return token;
}

static int add_token(char **result, int idx, const char *start, const char *end)
{
    result[idx] = make_token(start, end);
    if (!result[idx]) {
        free_tokens(result, idx);
        return -1;
    }
    return 0;
}

static int count_tokens(const char *str, char sep)
{
    int count = 0;
    int in_token = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != sep && !in_token) {
            in_token = 1;
            count++;
        }
        if (str[i] == sep)
            in_token = 0;
    }
    return count;
}

static int fill_tokens(char **result, const char *str, char sep)
{
    int idx = 0;
    const char *cur = str;
    const char *next;

    while (*cur) {
        while (*cur == sep)
            cur++;
        next = cur;
        while (*next && *next != sep)
            next++;
        if (cur == next)
            break;
        if (add_token(result, idx, cur, next) < 0)
            return -1;
        idx++;
        cur = next;
    }
    return idx;
}

char **split_line(const char *str, char sep)
{
    int n = count_tokens(str, sep);
    char **result = malloc(sizeof(char *) * (n + 1));

    if (!result)
        return NULL;
    if (fill_tokens(result, str, sep) < 0)
        return NULL;
    result[n] = NULL;
    return result;
}
