#include "hsh.h"
/**
 * _perrmsg - description
 * @av: char
 * @count: int
 */
void _perrmsg(char **av, int count)
{
	char *pcmd = getvar("_");

	pcmd = _strcat(pcmd, ":");
	/* _puts(pcmd); */
	printf("%s %i: %s: not found\n", pcmd, count, av[0]);
}
