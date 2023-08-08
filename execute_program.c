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

	/* Check for error */
	if (pid == -1)
	{
		return (FAILURE); /* fork failed */
	}
	/* Child process */
	if (pid == 0)
	{
		execve(op_path, string_array, NULL); /* run program */
		return (FAILURE); /* execve failed */
	}
	/* Parent process */
	else
	{
		/* Wait for child to finish */
		if (wait(&status) == -1)
		{
			return (FAILURE); /* wait failed */
		}
	}

	/* Check for normal termination */
	if (WIFEXITED(status))
	{
		/* Store exit status of child */
		exit_status = WEXITSTATUS(status);
		if (exit_status == 0)
			return (SUCCESS); /* executed correctly */
		else
			return (FAILURE); /* execute failed */
	}

	/* Child killed by signal */
	if (WIFSIGNALED(status))
		return (FAILURE);

	return (FAILURE); /* all other cases of failure */
}
