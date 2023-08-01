#include "main.h"

/**
 * string_tokens - tokenizes an input string
 * @string: pointer to the beginning of the string
 * Return: 0/1
 */

char **string_tokens(char *string)
{
	char **tokens = NULL;
	const char *delimiters = " ";
	int num_tokens = 0;
	char *token;
	int x;

	/* Make a copy of the input string */
	char *copy4Num = strdup(string);
	char *copy4Token = strdup(string);
	
	if (copy4Num == NULL || copy4Token == NULL)
	{
		perror("Copy has failed.\n");
		return (NULL);
	}
	/* Cut up string to count number of tokens */
	token = strtok(copy4Num, delimiters);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delimiters);
	}
	/* Allocate memory for new array */
	tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Memory allocation failed.\n");
		free(tokens);
		return (NULL);
	}
	/* Cut up second copy for tokenization */
	token = strtok(copy4Token, delimiters);
	printf("Number of tokens: %d\n", num_tokens);
	for (x = 0; x < num_tokens; x++)
	{
		tokens[x] = token;
		token = strtok(NULL, delimiters);
		printf("This is the for loop\n");
	}
	tokens[x] = NULL;

	return (tokens);
}
