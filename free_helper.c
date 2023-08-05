#include "main.h"

/**
 * free_string_array - Frees an array of strings.
 * @array: The array of strings to be freed.
 * Return: void
 */
void free_string_array(char **array)
{
	unsigned int i = 0;

	if (!array)
		return;
	if (!*array)
		return;

	for (; array[i]; i++)
	{
		free(array[i]);
	}
}

/**
 * free_string - Frees a single string.
 * @str: The string to be freed.
 * Return: void
 */
void free_string(char *str)
{
	if (str)
		free(str);
}

int free_the_mems(char **tokens_array, char **path_array)
{
	free_string_array(tokens_array);
	free_string_array(path_array);
	return (0);
}
