#include "main.h"

/**
 * main - test new functions
 * @argc: total number of arguments
 * @argv: each argument
 * Return: 0/1
 */

int main(int argc, char **argv)
{
	/* Defining Variables */
	char *print_pids, *max_pid, *prompt, *string;
	char **token;
	char **arg = argv;
	int x, child;
	(void)argc;

	/* Testing get_pid func */
	print_pids = get_pids();
	if (print_pids != NULL)
	{
		/* Prints parent and child PIDs */
		printf("Exercise 0 Output:\n%s\n", print_pids);
		free(print_pids);
	}
	else
		printf("Exercise 0 Failed\n");

	printf(br); /* line break */

	/* Testing pid_max func */
	max_pid = pid_max();
	if (max_pid != NULL)
	{
		/* Prints max PID */
		printf("Exercise 1 Output:\n%s \n", max_pid);
		free(max_pid);
	}
	else
		printf("Exercise 1 Failed\n");

	printf(br); /* line break */

	/* Testing argv and argc */
	arg++; /* Skip first argument, name of program */

	/* Print all arguments until NULL is found */
	if (argv[1] == NULL)
	{
		printf("No input found.\n");
		return(FAILURE);
	}

	while (*arg != NULL)
	{
		printf("%s ", *arg);
		arg++; /* Move to the next argument */
	}
	printf("\n\n");

	printf(br); /* line break */

	/* Test Read Line */
	prompt = read_line();
	if (prompt != NULL)
	{
		printf("%s", prompt);
		free(prompt);
	}

	printf(br);

	/* Test String Tokens */
	string = "I have two cats.  One is orange.";
	token = string_tokens(string);
	if (token != NULL)
	{
		for (x = 0; token[x] != NULL; x++)
		{
			printf("%s\n", token[x]);
		}
		/*for (x = 0; token[x] != NULL; x++)*/
			/*free(token[x]);*/
	}
	else
	{
		printf("String Tokenization Failed\n");
	}
	free(token);

	printf(br);

	/* Test execute_program */
	child = execute_program();
	if (child != FAILURE)
	{
		printf("Program returned:%d\n", child);
	}

	printf(br);

	/* Test 
	return (SUCCESS);
}
