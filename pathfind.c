#include <sys/stat.h>
#include "hsh.h"

char *pathfind(char *cmd)
{
	char *pathvar = _strdup(getenv("PATH"));
	char pd[1024], *pathd;
	char *ret = cmd;

	pathd = strtok(pathvar, ":");
	while (pathd)
	{
		_strcpy(pd, pathd);
		_strcat(pd, "/");
		if ((stat(strcat(pd, cmd), &buffer) == 0))
                        ret = _strdup(pd);

		pathd = strtok(NULL, ":");
	}
	free(pathvar);
	return (ret);
}

