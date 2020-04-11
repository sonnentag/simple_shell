#include "hsh.h"
/**
 * _strcpy - copy string from src to dest
 *
 * @dest: copy string location
 * @src: string to copy
 *
 * Return: copy content of src into dest
 */
char *_strcpy(char *dest, char *src)
{
	int string = 0;

	while (src[string] != '\0')
	{
		dest[string] = src[string];
		string++;
	}
	if (src[string] == '\0')
	{
		dest[string] = src[string];
	}
	return (dest);
}
