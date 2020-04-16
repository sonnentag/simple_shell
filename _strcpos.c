#include <stdlib.h>
#include "hsh.h"
/**
 * _strcpos - return position of character from string
 * @path: PATH
 * Return: c's position in string or -1
 */
int _strcpos(char *path)
{
	int i = 0;
	char c = 58;

	while (*path)
	{
		if ((*path == c) || (*path == 0))
		{
			return (i);
		}
		path++;
		i++;
	}

	return (-1);
}
