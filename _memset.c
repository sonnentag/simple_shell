#include "hsh.h"

/**
 * _memset - fill n memory with a constant byte
 * @s: memory buffer
 * @b: byte
 * @n: number to fill
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *buff = s;

	for (; n > 0; n--)
	{
		*buff++ = b;
	}

	return (s);
}
