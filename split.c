#include "hsh.h"

/**
 *
 *
 *
 */
char **split_line(char *line)
{
	int bufsize = 0, c = 0;
	char **buffer = malloc(bufsize * sizeof(char *));
	char *found;

	if (!buffer)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	found = strtok(line, " \n\r\t\a");
	while (found != NULL)
	{
		if (strcmp(found, "exit") == 0)
			exit(0);

		buffer[c] = found;
		c++;

		if (c >= bufsize)
		{
			bufsize += 64;
			buffer = realloc(buffer, bufsize * sizeof(char *));
			if (!buffer)
			{
				perror("Unable to reallocate buffer");
				exit(1);
			}
		}

		found = strtok(NULL, " \n\r\t\a");
	}
	buffer[c] = NULL;

	return (buffer);
}
