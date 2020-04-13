#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "hsh.h"

/**
 *
 *
 *
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		if (!isatty(STDIN_FILENO))
			exit(0);
		else
		{
			write(1, " ($) ", 5);
			fflush(stdout);
		}

		line = read_line();
		args = split_line(line);
		if (!builtincmd(args))
			launch(args);
	}
	return (0);
}
