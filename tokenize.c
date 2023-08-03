#include "main.h"

/**
 * tokenize - tokenizes an input string
 * @string: pointer to the beginning of the string
 * Return: 0/1
 */

char **tokenize(char *string)
{
	char **tokens_array = NULL;
	const char *delimiters = WHITESPACE1;
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
	tokens_array = (char **)malloc((num_tokens + 1) * sizeof(char *));
	if (tokens_array == NULL)
	{
		perror("Memory allocation failed.\n");
		return (NULL);
	}
	/* Cut up second copy for tokenization */
	token = strtok(copy4Token, delimiters);

	for (x = 0; x < num_tokens; x++)
	{
		tokens_array[x] = token;
		token = strtok(NULL, delimiters);
	}
	tokens_array[x] = NULL;

	free(copy4Num);
	/* free(copy4Token); */
	return (tokens_array);
}
