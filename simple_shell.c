#include "main.h"

void betty_no_more(void);

/**
 * main - the main function that houses simple shell
 * @argc: number of arguments
 * @argv: array of pointers to the arguments
 * @env: array of pointers to the environmental variables.
 * Return: 0/1
 */

int main(int argc, char **argv, char **env)
{
	/* Declare Variables */
	char **tokens_array = NULL, **path_array = NULL;
	size_t length = 0;
	int x = 0, operation = 0;
	char *line = NULL, *path = NULL;
	(void)argc;
	(void)argv;

	/* Infinite loop that keeps the shell running */
	while (true)
	{
	/* Interactive (person) or Non-Interactive (program) */
	if (isatty(STDIN_FILENO))
		printf("$: "); /* Display cursor if person */

	/* Take in input from user */
	if (getline(&line, &length, stdin) == -1)
	{
		break;
	}

	/* Edge case for just a new line character */
	cleanstr(line);

	/* Edge case for empty line */
	if (!tok_num(line, " "))
		continue;

	/* Tokenize input from user */
	tokens_array = tokstr(line, WHITESPACE1);

	/* Is the command a built-in function? */

	/* Compare input to "env" */
	if (strcmp(tokens_array[0], "env") == 0)
	{
		for (x = 0; env[x] != NULL; x++)
		{
			printf("%s\n", env[x]); /* Print each env variable */
		}
		free_string_array(tokens_array);
		continue;
	}

	/* Compare input to "exit" */
	if (strcmp(tokens_array[0], "exit") == 0)
	{
		free_string_array(tokens_array);
		break;
	}

	x = 0; /* reset x to 0 after for loop */

	/* Did the user indicate PATH=? */
	while (env[x] != NULL)
	{
		/* Compare first 5 to "PATH=" */
		if (strncmp(env[x], "PATH=", 5) == 0)
		{
			path = strdup((env[x] + 5)); /* store first 5 char */
			break;
		}
		x++;
	}

	/* Tokenize input from user */
	path_array = tokstr(path, WHITESPACE2);
	free(path);

	/* Check for access */
	if (access(tokens_array[0], X_OK) == 0)
	{
		/* Run called program */
		execute_program(tokens_array[0], tokens_array);
	}
	else
	{	/* Search for operation in path */
		operation = find_path(path_array, tokens_array);
	}

	/* Free memory */
	free_string_array(tokens_array);
	free_string_array(path_array);
	}
	if (line)
		free(line);
	
	/* Return output from program */
	return (operation);
}
