#include "shell.h"

/**
 * main - Main function of the shell
 * @ac: Argument count (unused)
 * @av: Argument vector (unused)
 * @env: Environment variables
 * Return: Shell exit status
 */

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **commands = NULL;
	int pathValue = 0, status = 0, is_path = 0;

	(void)ac;
	while (1)
	{
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
		is_path = _values_path(&commands[0], env);
		status = process_builtins(commands, env);
		if (status == 1)
		{
			free(commands);
			free(line);
			continue;
		}

		if (is_path == 0)
		status = _fork_fun(commands, av, env, line, pathValue, is_path);

		if (is_path == 0)
		free(commands[0]);

		free(commands);
		free(line);
	}

	return (status);
}

/**
 * process_builtins - Handle built-in commands (exit, env)
 * @commands: Tokenized user input
 * @env: Environment variables
 * Return: 1 if a built-in command is processed, otherwise 0
 */
int process_builtins(char **commands, char **env)
{
	if (!_strcmp(commands[0], "exit"))
	{
		free(commands[0]);
		free(commands);
		return (1);
	}
	else if (!_strcmp(commands[0], "env"))
	{
		_getenv(env);
		free(commands);
		return (1);
	}
	return (0);
}

