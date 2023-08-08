#include "main.h"

/**
 * free_string_array - Frees an array of strings.
 * @array: The array of strings to be freed.
 * Return: void
 */
void free_string_array(char **array)
{
	unsigned int i = 0;

	/* If array is a variable or just a single pointer */
	if (!array)
		return;
	if (!*array)
		return;

	/* Otherwise FREE EVERYTHING */
	for (; array[i]; i++)
	{
		free(array[i]);
	}
	free(array);
}
