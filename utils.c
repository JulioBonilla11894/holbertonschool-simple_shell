#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: String
 * Return: Length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
	len++;
	return (len);
}

/**
 * _strcmp - Compares two strings
 * @s1: String 1
 * @s2: String 2
 * Return: 0 if equal, non-zero otherwise
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _getline_command - Custom function to read input from user
 * Return: Input string
 */
char *_getline_command(void)
{
	size_t bufsize = 0;
	char *line = NULL;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * tokenize - Tokenizes the input string into commands
 * @line: Input string to tokenize
 * Return: Array of strings (commands)
 */
char **tokenize(char *line)
{
	char **tokens = malloc(sizeof(char *) * 64);
	int index = 0;
	char *token = strtok(line, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[index] = token;
		index++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[index] = NULL;
	return (tokens);
}
