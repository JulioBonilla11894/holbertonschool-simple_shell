#include "shell.h"

int process_builtins(char **commands, char **env)
{
    if (!_strcmp(commands[0], "exit"))
    {
        exit(0);
    }
    else if (!_strcmp(commands[0], "env"))
    {
        _getenv(env);
        return (1);
    }
    return (0);
}

void _getenv(char **env)
{
    int i;
    for (i = 0; env[i]; i++)
    {
        printf("%s\n", env[i]);
    }
}

int _strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
