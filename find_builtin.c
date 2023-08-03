#include "main.h"

/**
 * find_builtin - finds a built in function and runs it
 * @args: function
 */

void find_builtin(char **args)
{
	/* Declare and Initialize Variables */
	int x;

	/* Loop through array to find a function */
	for (x = 0; x < sizeof(a) / sizeof(builtInFunctions); x++)
	{
		if (strcmp(args[0], a[x].funcName) == 0) /* if they are the same */
		{
			a[i].funcPtr(args); /* run function */
			return;
		}
	}
	/* If not found... */
	perror("Error: ");
}
