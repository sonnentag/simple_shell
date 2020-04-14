#include "hsh.h"
/**
 * _strcat - concatenates two strings
 *
 * @dest: string one
 * @src: string two to connect to string one
 *
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int x = 0;
	int y = 0;

	while (dest[x] != '\0')
	{
		x++;
	}
	while (src[y] != '\0')
	{
		dest[x++] = src[y++];
	}
	*dest = '\0';
	return (dest);
}
