#include "shell.h"

/**
 * count_tokens - Count the number of tokens in a line.
 * @line: A pointer to the input line.
 * @line: A pointer to the line string.
 * @return: The number of tokens found, or -1 if an error occurs.
 */
int count_tokens(char *line)
{
	const char *delim = " \t\a\r\n";
	int counter = 0;
	char *token, *line_copy;

	line_copy = _strdup(line);
	if (line_copy == NULL)
		return (-1);

	token = strtok(line_copy, delim);
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, delim);
	}

	free(line_copy);
	return (counter);
}

/**
 * tokenize - Tokenize a line string into an array of string pointers.
 * @line: A pointer to the input line.
 *
 * @line: A pointer to the line string.
 * @return: An array of string pointers containing the tokens, or NULL
 *          if an error occurs or no tokens are found.
 */
char **tokenize(char *line)
{
	const char *delim = " \t\a\r\n";
	char **tokens;
	int i = 0, count;
	char *line_copy, *token;
	
	line_copy = _strdup(line);
	if (line_copy == NULL)
		return (NULL);

	count = count_tokens(line);
	if (count == -1 || count == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
		return (NULL);

	token = strtok(line_copy, delim);
	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;

	free(line_copy);
	return (tokens);
}
