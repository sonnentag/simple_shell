#include "hsh.h"
/**
 *
 *
 */
int builtincmd(char **argv)
{
	int x, rc;
	char *Builtinarray[] = {"exit", "cd", "env"}, *destdir;

	for (x = 0; x < 3; x++)
		if (strcmp(argv[0], Builtinarray[x]) == 0)
		    break;

		    switch (x)
		    {
		    case 0:
			    exit(0);
		    case 1:
			    destdir = argv[1];
			    rc = chdir(destdir);
			    if (rc)
				    perror("chdir failed");
			    else
				    setenv("PWD", destdir, 1);
		    case 2:
			    while (*environ)
				    printf("%s\n", *environ++);
		    default:
			    return (1);
		    }
		    return (0);
}
