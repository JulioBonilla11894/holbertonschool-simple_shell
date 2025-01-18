#include <unistd.h>
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
            printf("simple_shell: ");
        }

	line = malloc(1024 * sizeof(char));
	if (!line)
	{
		perror("malloc failed for line");
		return (1);
	}

        line = _getline_command();
        if (line == NULL)
	{
		free(line);
		break;
	}

	commands = malloc(100 * sizeof(char *));
	if (!commands)
	{
		perror("malloc failed for commands");
		free(line);
		return (1);
	}

	commands = tokenize(line);
	if (!commands)
	{
            free(line);
	    free(commands);
            continue;
        }

        pathValue++;
        if (_values_path(&commands[0], env) || access(commands[0], X_OK) == 0)
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
    }

    return (0);
}
