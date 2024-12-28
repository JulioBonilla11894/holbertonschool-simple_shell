#include "shell.h"

/**
* _command_line - GEts inputs
* Return: The input.
*/

char *command_line(void)
{
        char *lineptr = NULL;
        size_t charter_user = 0;

        if (isatty(STDIN_FILENO))
                writes(STDOUT_FILENO, "$ ", 2);

        if (getline(&lineptr, &charter_user, stdin) == -1)
        {
                free(lineptr);
                return (NULL);
        }

        return (lineptr);
}
