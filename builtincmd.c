#include "hsh.h"

/**
 * builtincmd - parse for builtin command and proceed accordingly
 * @argv: provided command line
 * Return: 1 if builtin matched, 0 otherwise
 */
int builtincmd(char **argv)
{
	int x, rc, ret = 0;
	char *Builtinarray[] = {"exit", "cd", "env"}, *destdir;
	char **envp, cwd[1024];

	for (x = 0; x < 3; x++)
		if (strcmp(argv[0], Builtinarray[x]) == 0)
		{
			switch (x)
			{
				case 0:
					exit(0);
				break;
				case 1:
					destdir = argv[1];
					if (argv[1] == NULL || argv[1] == "..")
					{
						destdir = "/home/vagrant";
					}
					rc = chdir(destdir);
					if (rc)
						perror("chdir failed");
					else
						getcwd(cwd, sizeof(cwd));
					ret = 1;
				break;
				case 2:
					envp = environ;
					while (*envp)
						printf("%s\n", *envp++);
					ret = 1;
				break;
			}
		}

	return (ret);
}
