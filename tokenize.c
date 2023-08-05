#include "main.h"

/**
 * tokenize - tokenizes an input string
 * @string: pointer to the beginning of the string
 * @delimiters: how to break up tokens
 * @token_array: where to store tokens
 * Return: 0/1
 */

char **tokenize(char *string, char *delimiters, char **tokens_array)
{
	int num_tokens = 0; /* Number of tokens */
	char *token; /* Pointer to first token */

	token = strtok(string, delimiters); /* cut out first token */

	if (token == NULL) /* Edge case for no string */
	{
		perror("No input given");
		exit(SUCCESS);
	}

	while (token != NULL) /* Go until NULL is found */
	{
		tokens_array[num_tokens] = token; /* Set first token into array */
		num_tokens++; /* count tokens */
		token = strtok(NULL, delimiters); /* cut out next token */
	}

	tokens_array[num_tokens] = NULL;

	return (tokens_array);
}
