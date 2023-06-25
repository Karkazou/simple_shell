#include "main.h"

/**
 * envar - prints the environment variables
 */

void envar(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * _write -> constructs a full path for an executable
 *
 * @line: input
 * @len: input
 * Return: 1
 */

ssize_t _write(char **line, size_t *len)
{
	ssize_t read = 0;

	if (isatty(STDIN_FILENO))
	{
		write(1, "($) ", 4);
	}
	read = getline(line, len, stdin);
	if (read == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			return (-1);
		}
		free(line);
		exit(EXIT_FAILURE);
	}
	return (read);
}
