#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <signal.h>
#include <ctype.h>

int process_builtins(char **commands, char **env);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_getline_command(void);
char **tokenize(char *line);
void _getenv(char **env);
int _values_path(char **command, char **env);
int _fork_fun(
<<<<<<< HEAD
	char **commands,
	char **av,
	char **env,
	char *line,
	int pathValue,
	int is_path);
=======
		char **commands,
		char **av,
		char **env,
		char *line,
		int pathValue,
		int is_path);
>>>>>>> 2f8c5355bf860d848a50afe396c3f5f0f829d82d

#endif
