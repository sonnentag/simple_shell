#include "hsh.h"
/**
 * _puts - prints a string, followed by a new line
 *
 * @str: string being printed
 *
 * Return: 0
 */
void _puts(char *str)
{
	int string = 0;

	while (str[string] != '\0')
	{
		_putchar(str[string]);
		string++;
	}
	_putchar('\n');
}
