#include "hsh.h"
/**
 *
 *
 */
int builtincmd(char *found)
{
	int x, rc;
	char Builtinarray[] = {"exit", "cd", "env"} , destdir;


	for (x = 0; x < 3; x++)
		if (strcmp(found[0], Builtinarray[x]) == 0)
			break;

	switch (x)
	{
	case 0:
		exit(0);
	case 1:
		destdir = found[1];
		rc = chdir(destdir);
		if (rc)
			perror("chdir failed");
		else
			setenv("PWD", destdir, 1);
		return (1);
	case 2:
		while (*environ)
			printf("%s\n", *environ++);
	default:
		break;
	}
	return (0);
}
