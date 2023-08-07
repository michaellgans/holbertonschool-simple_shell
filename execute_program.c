#include "main.h"

/**
 * execute_program - executes a program in a child process
 * @op_path: point to path containing the operation
 * @string_array: tokenized array
 * Return: 1/0
 */

int execute_program(char *op_path, char **string_array)
{
	/* Declare and Initialize Variables */
	pid_t pid;
	int status, exit_status;

	/* Fork process into child and parent */
	pid = fork();

	if (pid == -1)
		return (FAILURE); /* fork failed */
	if (pid == 0) /* child process */
	{
		execve(op_path, string_array, NULL); /* run program */
		return (FAILURE); /* execve failed */
	}
	else /* parent process */
	{
		if (wait(&status) == -1)
			return (FAILURE); /* wait failed */
	}

	/* Check for normal termination */
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status == 0)
			return (SUCCESS); /* executed correctly */
		else
			return (FAILURE); /* execute failed */
	}
	if (WIFSIGNALED(status)) /* child executed by signal */
		return (FAILURE); /* child killed by signal */

	return (FAILURE); /* all other cases of failure */
}
