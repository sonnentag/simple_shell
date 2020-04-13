#include "hsh.h"

/**
 *
 *
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int lc;

	lc = getline(&line, &bufsize, stdin);
	if (!lc)
		return (NULL);
	if (lc == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}

	return (line);
}
