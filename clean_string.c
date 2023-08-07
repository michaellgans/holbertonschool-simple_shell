#include "main.h"

/**
 * cleanstr - removes newline chars from user input
 * @line: user input line
 * Return: always 0
 */
int cleanstr(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
		}
		i++;
	}
	return (0);
}
