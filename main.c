#include "main.h"

/**
 * main - test new functions
 * Return: 0 success, 1 failure
 */

int main(void)
{
	/* Defining Variables */
	char *print_pids;
	char *max_pid;

	/* Testing get_pid func */
	print_pids = get_pids();
	if (print_pids != NULL)
	{
		printf("Exercise 0 Output:\n%s\n", print_pids);
		free(print_pids);
	}
	else
		printf("Exercise 0 Failed\n");

	printf(br);

	/* Testing pid_max func */
	max_pid = pid_max();
	if (max_pid != NULL)
	{
		printf("Exercise 1 Output:\n%s \n", max_pid);
		free(max_pid);
	}
	else
		printf("Exercise 1 Failed\n");

	return (SUCCESS);
}
