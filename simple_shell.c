#include "main.h"

/**
 * simple_shell - the main function that houses simple shell.
 * @argc: number of arguments.
 * @argv: each argument at index.
 * @env: environment
 * Return: SUCCESS/FAILURE (0/1)
 */

int simple_shell(int argc, char **argv, char **env)
{
	/* Declare and Initialize Variables */
	char **tokens_array; /* array of tokens */
	ssize_t read; /* reads input */
	size_t length = 0; /* length of what was read */
	char *line; /* what was read */
	int x; /* iterations */

	/* Start Program */
	while (true)
	{
		/* Array of Structs */
		builtInFunctions a[] = {
			{"exit", &builtin_exit},
			{"env", &builtin_env}
		};
		/* Interactive (person) or Non-Interactive (program) */
		if (isatty(STDIN_FILENO))
		{
			printf("Test: Input is coming from a person.\n");
			/* Display prompt for user. */
			printf("$: \n");
		}
		else
		{
			printf("Test: Input is coming from a program.\n");
		}
		/* Get input from user */
		read = getline(&line, &length, stdin);
		printf("Test: this is what the person typed: %s\n", line);
		if (read == -1)
			perror("Error: ");
		
		/* Tokenize Input - FREE ME */
		tokens_array = tokenize(line);
		if (tokens_array == NULL)
			perror("Error: ");
		/* Is the command a built in function? */
		find_builtin(tokens_array[x]);

		free(tokens_array);
		/* NOT Built In Functions */

	}
	return (SUCCESS);
}
