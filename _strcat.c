#include "hsh.h"

/**
 * _strcat - concatenate 2 strings
 * @src: provided source string
 * @dest: provided destination
 * Return: modified destination string
 */
char *_strcat(char *dest, char *src)
{
	void *ret = dest;

	while (*dest)
		dest++;
	while
		((*dest++ = *src++));
	*dest = (char)0;

	return (ret);
}
