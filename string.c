#include "shell.h"

/**
 * _strcmp - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: < 0 if str1 < str2, > 0 if str1 > str2, 0 if str1 == str2.
 */
int _strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

/**
 * _strlen - Calculate the length of a string.
 * @str: Input string.
 * Return: Length of the string (excluding the null terminator).
 */
size_t _strlen(const char *str)
{
    size_t len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    return (len);
}

/**
 * _strdup - Duplicate a string.
 * @src: Source string to duplicate.
 * Return: Duplicated string or NULL on failure.
 */
char *_strdup(const char *src)
{
    char *dest;
    size_t len = 0;
    size_t i;

    while (src[len])
        len++;

    dest = malloc((len + 1) * sizeof(char));

    if (dest == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        dest[i] = src[i];

    return (dest);
}

/**
 * _strcpy - Copy a string to a buffer.
 * @dest: Destination buffer.
 * @src: Source string to copy.
 * Return: Pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
    char *dest_start = dest;

    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return (dest_start);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: Destination buffer for the result.
 * @src: Source string to append to the destination.
 * Return: Pointer to the destination buffer.
 */
char *_strcat(char *dest, const char *src)
{
    char *temp = dest;

    while (*dest)
        dest++;

    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return (temp);
}
