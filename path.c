#include "shell.h"

/**
 * _values_path - Checks if a command exists in any of the directories listed
 * @command: The command to check
 * @env: Environment variable that holds the PATH
 * Return: 0 if found, 1 if not found
 */
int _values_path(char **command, char **env)
{
	char *path;
	char *path_copy;
	char *dir;
	struct stat st;
	char *full_path;
	(void) env;
	path = getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "PATH not found\n");
		return (1);
	}
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(_strlen(dir) + _strlen(*command) + 2);
		if (!full_path)
		{
			perror("Memory allocation error");
			free(path_copy);
			return (1);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, *command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			*command = full_path;
			return (0);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (1);
}

/**
 * _fork_fun - Forks a child process to execute the command
 * @commands: Command arguments
 * @av: Arguments
 * @env: Environment variables
 * @line: The input line
 * @pathValue: Command counter
 * @is_path: Flag for path existence
 * Return: Status code
 */

int _fork_fun(
		char **commands,
		char **av,
		char **env,
		char *line,
		int pathValue,
		int is_path)
{
	int status;
	pid_t pid;
	(void)av;
	(void)line;
	(void)pathValue;
	(void)is_path;

	pid = fork();
	if (pid == 0)
	{
		if (execve(commands[0], commands, env) == -1)
		{
			perror("execve failed");
			exit(1);
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
		return (1);
	}
	else
	{
		wait(&status);
		return (WEXITSTATUS(status));
	}
	return (0);
}
