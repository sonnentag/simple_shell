#include "hsh.h"

/**
 * _strchr - return character from string
 * @s: string
 * @c: character
 * Return: remainder of string or 0
 */
char *_strchr(char *s, char c)
{

	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (0);
}
