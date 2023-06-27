#include "main.h"


/**
 * _input -> test the tab
 * @str: input
 * Return: 1
 */

int _input(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	}
	return (1);
}


/**
 * shell -> shell
 */

void shell(void)
{
	char *str = NULL, *arg[10], *arg1 = "/bin/", *commend;
	size_t strlen = 0;
	ssize_t len;
	int status_exit = -1;

	while ((len = _write(&str, &strlen)) != -1)
	{
		if (str[len - 1] == '\n')
			str[len - 1] = '\0';
		if (str[0] == '\0')
			continue;
		if (_input(str))
			break;
		if (strcmp(str, "env") == 0)
		{
			envar();
			free(str);
			free(commend);
			exit(EXIT_SUCCESS);
		}

		_strtok(str, arg);
		if (strcmp(arg[0], "exit") == 0)
			h_exit(arg, str, status_exit);
		_path(arg[0], arg1, &commend);
		status_exit = run(arg, commend, str);
	}
	free(str);
}
