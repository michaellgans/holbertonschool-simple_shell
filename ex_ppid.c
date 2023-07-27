#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - prints the parent pid
 * Return: 0 - child -1 error
 */

int main(void)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("This is a spoon...");
		return (1);
	}
	else if (pid == 0)
	{
		/* Child process */
		printf("The child PID is: %d\n", getpid());
		printf("The PPID is %d\n", getppid());
	}
	else
	{
		/*Parent Process */
		printf("The parent PID is: %d\n", getpid());
		printf("This is the child PID from parent: %d\n", pid);
	}
	return (0);
}
