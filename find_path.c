#include "main.h"
#include <sys/stat.h>

/**
 * find_path - finds the operation by traversing through a path
 * @path_array: array of strings with different directories
 * @args_array: array of strings of arguments to be executed
 * Return: 1/0
 */

int find_path(char **path_array, char **args_array)
{
	/* Declare and Initialize Variables */
	int x = 0;
	char *temp = NULL; /* temporary pointer */

	/* Continue until null byte is found */
	while (path_array[x] != NULL)
	{
		/* Allocate memory */
		temp = malloc(strlen(args_array[0]) + strlen(path_array[x]) + 2);

		strcpy(temp, path_array[x]); /* start array */
		strcat(temp, "/"); /* add a slash */
		strcat(temp, args_array[0]); /* add operation */

		/* Check to see if the program exists */
		if (access(temp, F_OK) == 0)
		{
			/* Run program */
			execute_program(temp, args_array);
			free(temp);
			return (SUCCESS);
		}
		free(temp);
		x++;
	}
	return (127); /* indicate no valid operation was found */
}
