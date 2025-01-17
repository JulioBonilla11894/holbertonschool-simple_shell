#include "shell.h"

char *_getline_command(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}

char **tokenize(char *line)
{
    char **tokens = malloc(sizeof(char *) * 1024);
    char *token;
    int i = 0;

    if (!tokens)
    {
        perror("Malloc failed");
        return (NULL);
    }

    token = strtok(line, " \t\n");
    while (token)
    {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return tokens;
}
