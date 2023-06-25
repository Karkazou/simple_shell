#include "main.h"

/**
 * _strtok -> constructs a full path for an executable
 *
 * @line: input
 * @arg: input
 * Return: int
 */

int _strtok(char *line, char **arg)
{
	int i;
	char *tock;

	for (tock = strtok(line, " \t\n\"\'\\#&*`"), i = 0; tock != NULL;
			tock = strtok(NULL, " \t\n\"\'\\#&*`"), i++)
	{
		arg[i] = tock;
	}
	arg[i] = NULL;
	return (i);
}
