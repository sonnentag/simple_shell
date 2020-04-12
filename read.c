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

	return (line);
}
