#include "hsh.h"

/**
 * _perrmsg - write sh style error to stderr
 * @av: argv with command line
 * @count: command count
 */
void _perrmsg(char **av, int count)
{
	char c;

	write(STDERR_FILENO, getvar("_"), _strlen(getvar("_")));
	write(STDERR_FILENO, ": ", 2);
	if (count > 99)
	{
		c = (count / 100 + '0');
		_puterrc(c);
	}
	if (count > 9)
	{
		c = (count / 10 + '0');
		_puterrc(c);
	}
	c = (count % 10 + '0');
	_puterrc(c);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * _puterrc - put character to err
 * @c: character to put
 * Return: char to stderr
 */
int _puterrc(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
