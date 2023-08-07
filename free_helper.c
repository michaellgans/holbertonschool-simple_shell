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
    free(array);
}
