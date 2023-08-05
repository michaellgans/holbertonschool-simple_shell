#include "main.h"
/**
 * main - the main function that houses simple shell.
 * @argc: number of arguments.
 * @argv: array of pointers to the arguments
 * @env: array of pointers to the enviornmental variables.
 * Return: SUCCESS/FAILURE (0/1)
 */
int main(int argc, char **argv, char **env)
{
	char *tokens_array[20], *path_array[20]; /* array of tokens */
	size_t length = 0; /* length of what was read */
	int x = 0, operation = 0; /* iterations */
	char *line, *path; /* what was read, beginning of path*/
	(void)argc;
	(void)argv;

	while (true) /* Infinate loop that keeps the prog running */
	{
		while (env[x] != NULL) /* Check for path given */
		{
			if (strncmp(env[x], "PATH=", 5) == 0)
			{
				path = strdup((env[x] + 5)); /* Store first 5 char into path */
				break; /* try continue here */
			}
			x++;
		}
		tokenize(path, WHITESPACE2, path_array); /* save for later */

		/* Interactive (person) or Non-Interactive (program) */
		if (isatty(STDIN_FILENO))
			printf("$: "); /* Display curser if person */

		/* Get input from user */
		if (getline(&line, &length, stdin) == -1)
		{
			free(line);
			free(path);
			exit(SUCCESS);
		}

		/* Tokenize Input */
		tokenize(line, WHITESPACE1, tokens_array);
		if (tokens_array[0] == NULL) /* Edge case for no input given */
		{
			free(path);
			continue;
		}

		/* Is the command a built in function? */
		if (strcmp(tokens_array[0], "env") == 0)
		{
			for (x = 0; env[x] != NULL; x++)
			{
				printf("%s\n", env[x]);
			}
			free(path);
			continue;
		}

		if (strcmp(tokens_array[0], "exit") == 0)
		{
			free(line);
			free(path);
			exit(SUCCESS);
		}

		/* Check for access */
		/*if (access(tokens_array[0], X_OK) == 0)
			EXECUTE PROGRAM HERE(path, tokens_array[0], args);
		else
			operation = CHECK PATH(path, paths_array, args); */
	}
	return (operation);
}
