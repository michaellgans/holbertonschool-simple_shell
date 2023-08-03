#include "main.h"

/**
 * execute_program - executes a program in a child process
 * Return: 1/0
 */

int execute_program(void)
{
	/* Declare and Initialize Variables */
	pid_t pid;
	int x, status;
	const char *pathname = "/bin/ls";
	char *const argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	char *const env[] = {NULL};
	int num_runs = 5;

	/* fork into child and parent */
	for (x = 0; x < num_runs; x++)
	{
		printf("This is before we fork\n");

		pid = fork();
		if (pid == -1)
		{
			perror("Fork did not work\n");
			return (FAILURE);
		}
		/* run a program */
		if (pid > 0) /* indicates it's a parent */
		{
			/* make parent wait */
			wait(&status);
			printf("Child %i exited with status: %i\n", x + 1, WEXITSTATUS(status));
		}
		else if (pid == 0)
		{
			execve(pathname, argv, env); /* run ls */
			/* return output from child to parent */
			perror("Program didn't run.\n");
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
