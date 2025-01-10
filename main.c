#include "shell.h"

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    char **commands = NULL;
    int pathValue = 0, status = 0;
    int interactive_mode = isatty(STDIN_FILENO);

    (void)ac;
    while (1)
    {
        if (interactive_mode)
        {
            printf("yoruan_shell: ");
        }

        line = _getline_command();
        if (!line)
            return (0);

        commands = tokenize(line);
        if (!commands)
        {
            free(line);
            continue;
        }

        pathValue++;
        if (access(commands[0], X_OK) == 0)
        {
            status = _fork_fun(commands, av, env, line, pathValue, 1);
        }
        else
        {
            status = process_builtins(commands, env);
            if (status == 0)
                fprintf(stderr, "%s: Command not found\n", commands[0]);
        }

        free(commands);
        free(line);

        if (!interactive_mode && feof(stdin))
            break;
    }

    return (0);
}
