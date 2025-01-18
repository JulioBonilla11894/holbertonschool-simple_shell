#include "shell.h"
#include <stdlib.h>

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
    char *env_var = (char *)malloc(256 * sizeof(char));
    if (env_var == NULL)
    {
	perror("malloc failed");
    	exit(1);
    }
    for (i = 0; env[i]; i++)
    {
	snprintf(env_var, 256, "%s", env[i]);
        printf("%s\n", env[i]);
    }
    free(env_var);
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
