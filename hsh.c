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
	int r = 1;

	while (r == 1)
	{
		if (!isatty(STDIN_FILENO))
			r = 0;
		else
		{
			write(1, " ($) ", 5);
			fflush(stdout);
		}
/* handle signal(SIGINT, ...handler); */

		line = read_line();
		if (line)
			args = split_line(line);
		if (args)
			if (!builtincmd(args))
				launch(args);
	}
	return (0);
}
