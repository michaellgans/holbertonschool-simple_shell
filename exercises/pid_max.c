#include "main.h"

/**
 * pid_max - prints the maximum PID possible
 * Return: 0 success 1 error
 */

char *pid_max(void)
{
	/* Define and Initialize Variables */
	char *message;
	pid_t pid = getpid();

	/* Error Edge Case */
	if (pid == -1)
	{
		perror("Unable to retrieve PID\n");
		return (NULL);
	}

	/* Prints current, then Max PID */
	message = malloc(100);

	if (message != NULL)
		sprintf(message, "Maximum PID Possible: %u\n", UINT_MAX);

	return (message);
}
