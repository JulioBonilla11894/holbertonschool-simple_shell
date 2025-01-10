#include "shell.h"
/**
 * _fork_fun - Creates a child process to execute a command.
 * @commands: The tokenized user input containing the command and arguments.
 * @av: The argument vector (unused in this function).
 * @env: The environment variables array.
 * @line: The user input line (to be freed if the process is successful).
 * @pathValue: A value related to the path (unused in this function).
 * @is_path: A flag indicating if the command is a valid path.
 *
 * Return: 0 on success, 1 if there was an error.
 */
int _fork_fun(char **commands, char **av, char **env, char *line,
			int pathValue, int is_path)
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
