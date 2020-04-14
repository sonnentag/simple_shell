#include "hsh.h"
/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 or difference between string one and string two
 */
int _strcmp(char *s1, char *s2)
{
	int x = 0, ret, s1len, s2len;

	s1len = _strlen(s1);
	s2len = _strlen(s2);

	while ((s1len && s2len) && s1[x] == s2[x])
		x++;

	if (s1[x] == '\0' && s2[x] == '\0')
	{
		ret = 0;
	}
	else
	{
		ret = s1[x] - s2[x];
	}
	return (ret);
}
/**
 * _strlen - returns the length of a string
 *
 * @s: string being measured for length
 *
 * Return: 0
 */
int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}
