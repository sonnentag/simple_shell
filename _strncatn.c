#include "hsh.h"
/**
 * _strncatn - concatenate two strings starting at index n
 * @str: provided source string
 * @n: number of characters to cat
 * Return: modified destination string
 */
char *_strncatn(char *str, int n)
{
	while (n >= 0)
	{
		str++;
		n--;
	}
	printf("%s\n", str);

	return (str);
}
