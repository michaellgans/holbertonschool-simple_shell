#include "main.h"

/**
 * find_path - finds the operation by traversing through a path
 * @path: pointer to PATH environmental variable
 * @path_array: array of strings with different directories
 * @args: array of strings of arguments to be executed
 * Return: 1/0
 */

int find_path(char **path_array, char **args_array)
{
	int x = 0; /* iterator */
	char *temp = NULL; /* temporary pointer */
	struct stat info; /* stores attributes or details */

	while (path_array[x] != NULL)
	{
		temp = malloc(strlen(args_array[0]) + strlen(path_array[x]) + 2);
		strcpy(temp, path_array[x]); /* start array */
		strcat(temp, "/"); /* add a slash */
		strcat(temp, args_array[0]); /* add operation */
		if (stat(temp, &info) == 0) /* does the program exist? */
		{
			execute_program(temp, args_array);
			free(temp);
			return (SUCCESS);
		}
		free(temp);
		x++;
	}
	return (127); /* indicate no operation was found */
}
