#include "main.h"

/**
 * get_pids - prints the parent pid
 * Return: 0 - child -1 error
 */

char *get_pids(void)
{
	/* Defining Variables */
	char *message = NULL;

	/* Allocate Memory */
	message = malloc(100);
	if (message != NULL)
	{
		sprintf(message, "Child PID: %d\nPPID: %d\n", getpid(), getppid());
	}
	return (message);
}
