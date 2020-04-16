#include "hsh.h"
/**
 * **split_line - parses line read from the command line
 * @line: line read from the command line
 * Return: buffer of parsed commands
 */
char **split_line(char *line)
{
	int bufsize = 1024, c = 0;
	char **buffer = malloc(bufsize * sizeof(char *));
	char *found;

	if (!buffer)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		exit(1);
	}

	found = strtok(line, " \n\r");
	if (found == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (found != NULL)
	{
		buffer[c] = found;
		c++;
		found = strtok(NULL, " \n\r");
	}
	buffer[c] = NULL;
	return (buffer);
}
