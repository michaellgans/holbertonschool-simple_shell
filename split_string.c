#include "main.h"

/**
 * split_string - splits a string into tokens
 * @string: pointer to the start of the string
 * @words: Max number of words
 * Return: 0/1
 */

int split_string(char *string, char *words[MAX_WORDS])
{
	/* Define Variables */
	int x;
	char *token;

	/* Initialize Variables */
	x = 0;
	token = strtok(string, " ");

	/* Loop through tokens */
	while (token != NULL && x < MAX_WORDS)
	{
		words[x++] = token; /* stores into array & incements */
		token = strtok(NULL, " "); /* gets next token */
	}
	return (x);
}
