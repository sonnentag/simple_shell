#include "hsh.h"

/**
 * _strncpy - copy n chars of string
 * @dest: provided destination
 * @src: provided source
 * @n: number of chars to copy
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	void *ret = dest;

	while (n > 0 && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dest = (char)0;
		dest++;
		n--;
	}

	return (ret);
}
