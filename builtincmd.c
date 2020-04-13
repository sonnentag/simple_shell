#include "hsh.h"
/**
 *
 *
 */
int builtincmd(char **argv)
{
	int x, rc, ret = 0;
	char *Builtinarray[] = {"exit", "cd", "env"}, *destdir;

	for (x = 0; x < 3; x++)
		if (strcmp(argv[0], Builtinarray[x]) == 0)
		{
		    switch (x)
		    {
		    case 0:
			    exit(0);
			    ret = 1;
			    break;
		    case 1:
			    destdir = argv[1];
			    rc = chdir(destdir);
			    if (rc)
				    perror("chdir failed");
			    else
				    setenv("PWD", destdir, 1);
			    ret = 1;
			    break;
		    case 2:
			    while (*environ)
				    printf("%s\n", *environ++);
			    ret = 1;
			    break;
		    }
		}
		    return (ret);
}
