#include "shell.h"

int _fork_fun(char **commands, char **av, char **env, char *line, int pathValue, int is_path)
{
    pid_t pid;
    int status;

    (void)pathValue;
    (void)is_path;

    pid = fork();
    if (pid == -1)
    {
        perror("Error forking");
        return (1);
    }

    if (pid == 0)
    {
        if (execve(commands[0], commands, env) == -1)
        {
            perror(av[0]);
            free(commands);
            free(line);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }
    return (0);
}
