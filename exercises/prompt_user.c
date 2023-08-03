#include "main.h"

/**
 * read_line - prompts, reads, and prints input.
 * Return: 0/1
 */

char *read_line(void)
{
	/* Declare Variables */
	char *message, *line = NULL;
	size_t length = 0;
	ssize_t read;

	printf("$Hello!  Please enter your command here: "); /* prints cursor to console */
	fflush(stdout); /* Ensures the cursor is displayed to stdout */

	/* Take in input */
	read = getline(&line, &length, stdin);

	/* allocate memory */
	message = (char *)malloc(100);
	if (message == NULL)
	{
		free(line);
		return (NULL);
	}

	/* Print input given */
	if (read != -1) /* successfully read stdin */
	{
		/* Tokenize */
		string_token(line);
	}

	free(line);

	return (line);
}
