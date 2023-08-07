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
	char **tokens_array = NULL, **path_array = NULL;
	size_t length = 0;
	int x = 0, operation = 0;
	char *line = NULL, *path = NULL;
	(void)argc;
	(void)argv;

	while (true) /* Infinate loop: keeps program running */
	{
		/* Interactive (person) or Non-Interactive (program) */
		if (isatty(STDIN_FILENO))
		{
			printf("$: "); /* Display curser if person */
		}

		/* Get input from user */
		if (getline(&line, &length, stdin) == -1)
		{
			free(line);
			/* free(path); */
			break;
		}

		cleanstr(line); /* Remove newline char */

		tokens_array = tokenize(line); /* HEEEEEEEEEERE */

		/* Is the command a built in function? */
		if (strcmp(tokens_array[0], "env") == 0)
		{
			for (x = 0; env[x] != NULL; x++)
			{
				printf("%s\n", env[x]);
			}
			free_string_array(tokens_array);
			continue;
		}

		if (strcmp(tokens_array[0], "exit") == 0)
		{
			free_string_array(tokens_array);
			break;
		}
		x = 0;

		/* Not built in functions */
		while (env[x] != NULL) /* Check for path given */
		{
			if (strncmp(env[x], "PATH=", 5) == 0)
			{
				path = strdup((env[x] + 5)); /* store first 5 char */
				break;
			}
			x++;
		}
		path_array = tokenize(path); /* HEEEEEEEEEERE */
		free(path);

		/* Check for access */
		if (access(tokens_array[0], X_OK) == 0)
		{
			execute_program(tokens_array[0], tokens_array);
		}
		else
		{
			operation = find_path(path_array, tokens_array);
		}

	free(tokens_array);
	free(path_array);
	}
	return (operation);
}

