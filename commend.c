#include "main.h"

/**
 * bintest -> checks whether an executable path belongs to /bin/
 *
 * @str: input
 *
 * Return: 1 on success and 0 on failure
 */

int bintest(char *str)
{
	char *path = "/bin/";

	while (*path != '\0')
	{
		if (*path != *str)
		{
			return (0);
		}
		path = path + 1;
		str = str + 1;
	}
	return (1);
}

/**
 * _path -> constructs a full path for an executable
 *
 * @str: input
 * @path: input
 * @commend: input
 *
 */

void _path(char *str, char *path, char **commend)
{
	int len;

	if (bintest(str))
	{
		len = 1 + strlen(str);
		*commend = (char *)malloc(sizeof(char) * len);
		strcpy(*commend, str);
	}
	else
	{
		switch (str[0])
		{
			case '.':
			case '/':
				len = 1 + strlen(str);
				*commend = (char *)malloc(sizeof(char) * len);
				strcpy(*commend, str);
				break;

			default:
				len = strlen(path) + 2 + strlen(str);
				*commend = (char *)malloc(sizeof(char) * len);

				strcpy(*commend, path);
				strcat(*commend, str);

				break;
		}
	}
}
