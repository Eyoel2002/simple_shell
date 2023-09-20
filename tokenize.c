#include "shell.h"

/**
 * count_tokens - Count the number of tokens in a line.
 * @line: A pointer to the input line.
 *
 * This function takes an input line and counts the number of tokens
 * separated by whitespace characters such as spaces and tabs.
 *
 * @param line: A pointer to the line string.
 * @return: The number of tokens found, or -1 if an error occurs.
 */
int count_tokens(char *line)
{
    const char *delim = " \t\a\r\n";
    int counter = 0;
    char *token, *line_copy;

    // Duplicate the input line for tokenization.
    line_copy = _strdup(line);
    if (line_copy == NULL)
        return (-1);

    // Tokenize the duplicated line and count tokens.
    token = strtok(line_copy, delim);
    while (token != NULL)
    {
        counter++;
        token = strtok(NULL, delim);
    }

    // Free the duplicated line and return the token count.
    free(line_copy);
    return (counter);
}

/**
 * tokenize - Tokenize a line string into an array of string pointers.
 * @line: A pointer to the input line.
 *
 * This function takes an input line and tokenizes it, creating an array
 * of string pointers where each pointer represents a token from the line.
 *
 * @param line: A pointer to the line string.
 * @return: An array of string pointers containing the tokens, or NULL
 *          if an error occurs or no tokens are found.
 */
char **tokenize(char *line)
{
    const char *delim = " \t\a\r\n";
    char **tokens;
    int i = 0, count;
    char *line_copy, *token;

    // Duplicate the input line for tokenization.
    line_copy = _strdup(line);
    if (line_copy == NULL)
        return (NULL);

    // Count the tokens in the duplicated line.
    count = count_tokens(line);
    if (count == -1 || count == 0)
        return (NULL);

    // Allocate memory for the array of string pointers.
    tokens = malloc(sizeof(char *) * (count + 1));
    if (!tokens)
        return (NULL);

    // Tokenize the duplicated line and store tokens in the array.
    token = strtok(line_copy, delim);
    while (token != NULL)
    {
        tokens[i] = _strdup(token);
        token = strtok(NULL, delim);
        i++;
    }
    tokens[i] = NULL;

    // Free the duplicated line and return the array of tokens.
    free(line_copy);
    return (tokens);
}
