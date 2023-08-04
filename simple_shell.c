#include "main.h"

/**
 * main - the main function that houses simple shell.
 * @argc: number of arguments.
 * @argv: each argument at index.
 * @env: environment
 * Return: SUCCESS/FAILURE (0/1)
 */

int main(int argc, char **argv, char **env)
{
	/* Declare and Initialize Variables */
	char **tokens_array; /* array of tokens */
	size_t length = 0; /* length of what was read */
	char *line; /* what was read */
	int x; /* iterations */
	(void)argc;
	(void)argv;

	/* Start Program */
	while (true)
	{
		/* Interactive (person) or Non-Interactive (program) */
		if (isatty(STDIN_FILENO))
			printf("$: "); /* Display curser if person */
		/* Get input from user */
		if (getline(&line, &length, stdin) == -1)
		{
			free(line);
			perror("Error: ");
			exit(SUCCESS);
		}
		/* Tokenize Input - FREE ME */
		tokens_array = tokenize(line);
		if (tokens_array == NULL)
			perror("Error: ");
		/* Is the command a built in function? */
		if (strcmp(tokens_array[0], "env") == 0)
		{
			for (x = 0; env[x] != NULL; x++)
			{
				printf("%s\n", env[x]);
			}
		}
		if (strcmp(tokens_array[0], "exit") == 0)
		{
			exit(0);
		}
		free(tokens_array);
		free(line);
		/* NOT Built In Functions */
	}
	return (SUCCESS);
}
