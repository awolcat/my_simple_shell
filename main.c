#include "main.h"

void free_str(char *buffer, char *getline_cp);

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: 0 is success
 */

int main(__attribute__((unused))int argc, char *argv[], char *env[])
{
	size_t bytes;
	int retval = 0;

	while (1)
	{
		char *buffer = NULL, *delim = " ", *getline_cp, **tokens = NULL;
		int args = 0, ret = 0;

		if (isatty(STDIN_FILENO))
			get_prompt();

		ret = getline(&buffer, &bytes, stdin);
		if (ret == -1)
			exit(ret);

		buffer[_strlen(buffer) - 1] = '\0';
		getline_cp = _strdup(buffer);
		args = no_of_args(buffer, delim);

		if (args > 1)
		{
			tokens = word_split(getline_cp, delim);
			free_str(buffer, getline_cp);
			retval = exec_builtin(tokens, env, argv);
			if (retval == -1)
			{
				retval = _fork(tokens, env, argv);
				free_grid(tokens, args);
			}
		}
		else
			free_str(buffer, getline_cp);
	}
	return (retval);
}

/**
 * free_str - frees all dynamically allocated memory in shell_clone.c
 * @buffer: string to free
 * @getline_cp: string to free
 *
 * Return: Void
 */

void free_str(char *buffer, char *getline_cp)
{

	free(buffer);
	free(getline_cp);

}
