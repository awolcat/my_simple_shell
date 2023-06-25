#include "main.h"

/**
 * _fork - handles the fork
 * @tokens: an array of pointers to strings
 * @env: an array of pointers to strings, specifically env variables
 * @argv: the argv[0] string
 * @filename: a string containing the absolute path of a file
 *
 * Return: Void
 */

int _fork(char **tokens, char **env, char **argv)
{
	int retval = 0, pid = 0, status;

	retval = file_check(tokens, env);

	if (retval != 0)
	{
		cmd_not_found_error(argv[0], tokens[0]);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(98);
	}
	else if (pid == 0)
	{
		if (retval == 0)
			our_execve(tokens, env);
	}
	else
		wait(&status);
	return (status);
}
