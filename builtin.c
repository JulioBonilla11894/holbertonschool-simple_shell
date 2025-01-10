#include "shell.h"
/**
 * process_builtins - Checks if a command is a built-in command and processes.
 * @commands: An array of strings containing the tokenized user input.
 * @env: The environment variables array.
 *
 * Return: 1 if a built-in command was processed, 0 otherwise.
 */
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

/**
 * _getenv - Prints the environment variables.
 * @env: The environment variables array.
 */
void _getenv(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, a positive integer if s1 > s2,
 *         and a negative integer if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
