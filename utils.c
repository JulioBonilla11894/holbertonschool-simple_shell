#include "shell.h"
/**
 * _getline_command - Reads a line of input from the user.
 *
 * Return: Pointer to the line read from stdin. Returns NULL if an error occurs
 *         or end of file is reached.
 */
char *_getline_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/**
 * tokenize - Tokenizes a string into an array of words.
 * @line: The input string to be tokenized.
 *
 * Return: An array of tokens (strings). Each token is a word separated by
 *         spaces, tabs, or newlines. Returns NULL if memory allocation fails.
 */
char **tokenize(char *line)
{
	char **tokens = malloc(sizeof(char *) * 1024);
	char *token;
	int i = 0;

	if (!tokens)
	{
		perror("Malloc failed");
		return (NULL);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
