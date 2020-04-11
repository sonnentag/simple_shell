#include "hsh.h"
/**
 * *_strdup - duplicates a string to a newly allocated space in memory
 * @str: pointer to string
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int x, y;

	if (str == NULL)
	{
		return (NULL);
	}
	for (x = 0; str[x] != '\0'; x++)
	{
		;
	}
	copy = malloc(x + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	for (y = 0; y <= x; y++)
	{
		copy[y] = str[y];
	}
	return (copy);
}
