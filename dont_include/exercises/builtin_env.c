#include "main.h"

/**
 * builtin_env - runs exit
 * @args: argument calling exit
 */

void builtin_env(char **args)
{
	/* Define Variables */
	extern char **environ;

	(void)args;

	char **env = environ;

	/* test */
	printf("Test: builtin_env was called.\n");

	/* print all enviornments */
	for (; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
