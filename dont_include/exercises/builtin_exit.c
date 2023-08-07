#include "main.h"

/**
 * builtin_exit - runs exit
 * @args: argument calling exit
 */

void builtin_exit(char **args)
{
	printf("Test: Exit was called\n");
	exit(0);
}
