#include "main.h"

/** cleanstr - removes newline characters from user input
 * @line: user input line
 * Return: 0/1
 */

int cleanstr(char *line)
{
	int x = 0;

	while (line[x])
	{
		if(line[x] == '\n')
		{
			line[x] = '\0';
		}
		x++;
	}
	return (SUCCESS);
}
