#include "main.h"


/**
 * env - prints the environment variables
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

void shell(void)
{
    char *str = NULL, *arg[10], *arg1 =  "/bin/", *commend;
    size_t strlen = 0;
	ssize_t len;

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
			exit(EXIT_SUCCESS);
		}
		
		_strtok(str, arg);
		_path(arg[0], arg1, &commend);
		execute(arg, commend, str);
    }
    
}