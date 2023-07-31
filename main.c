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
	char *print_pids, *max_pid, *prompt, *words[MAX_WORDS];
	char **arg = argv;
	char string[];
	int x, num_words;
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
	num_words = split_string(string, words);

	for (x = 0; x < num_words; x++)
		printf("%s", words[x]);
	printf("\n");

	return (SUCCESS);
}
