#include "main.h"

/**
 * execute -> forks a child process and runs the specified command
 *
 * @arg: input
 * @full: input
 * @line: input
 * Return: exit status of fork
 */

int execute(char **arg, char *commend, char *str)
{
	int pid = fork();
	int status = 0;
	int f_status = 0;

	if (pid == 0)
	{
		if (execve(commend, arg, NULL) == -1)
		{
			free(commend);
			free(str);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(commend);
		if (WIFEXITED(status))
			f_status = WEXITSTATUS(status);
	}
	return (f_status);
}