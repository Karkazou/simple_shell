#include "main.h"

/**
 * chernum -> exit
 * @str: input
 * Return: int
 */

int chernum(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * h_exit -> exit
 *
 * @arg: input
 * @status_exit: input
 * @str: input
 */

void h_exit(char *arg[], char *str, int status_exit)
{
	int i = 0;
	char *error = "./hsh: 1: exit: Illegal number: ";

	if (arg[1])
	{
		if (arg[1][0] != '-' && chernum(arg[1]))
			status_exit = atoi(arg[1]);
		else
		{
			while (error[i])
			{
				write(STDERR_FILENO, &error[i], 1);
				i++;
			}
			i = 0;
			while (arg[1][i])
			{
				write(STDERR_FILENO, &arg[1][i], 1);
				i++;
			}
			write(STDERR_FILENO, "\n", 1);
			status_exit = 2;
		}
	}
	else if (status_exit == -1)
		status_exit = EXIT_SUCCESS;
	free(str);
	exit(status_exit);
}
