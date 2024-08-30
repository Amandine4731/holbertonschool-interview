#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a string.
 * @str: The string to check.
 * @pattern: The pattern to check against.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
 
int regex_match(const char *str, const char *pattern)
{
    if (*pattern == '\0')
        return (*str == '\0');

    int first_match = (*str && (*str == *pattern || *pattern == '.'));

    if (*(pattern + 1) == '*')
    {
        return (regex_match(str, pattern + 2) ||
                (first_match && regex_match(str + 1, pattern)));
    }
    else
    {
        return (first_match && regex_match(str + 1, pattern + 1));
    }
}
