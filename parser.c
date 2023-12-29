#include "shell.h"

#define TOKEN_DELIMITERS " \t\n\r" /* Define TOKEN_DELIMITERS */

/**
 * parse_input - Parse the input command line into an array of tokens.
 * @input: The input command line.
 *
 * Return: An array of tokens (strings).
 */
char **parse_input(const char *input) /* Use const char * for input */
{
	char **tokens;
	char *token;
	size_t token_count = 0; /* Use size_t for token_count */
	char *input_copy; /* Make a copy of the input string */

	tokens = malloc(MAX_TOKENS * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	input_copy = strdup(input); /* Make a copy of the input string */
	token = strtok(input_copy, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		tokens[token_count] = token;
		token_count++;

		if (token_count >= MAX_TOKENS)
		{
			fprintf(stderr, "Too many tokens\n");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, TOKEN_DELIMITERS); /* Use NULL instead of TOKEN_DELIMITERS */
	}

	tokens[token_count] = NULL; /* Mark the end of the array with NULL */
	free(input_copy); /* Free the input copy */
	free(tokens); /* Free the tokens array */
	return tokens;
}

