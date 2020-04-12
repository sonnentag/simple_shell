#include <sys/stat.h>
#include "hsh.h"

char *pathfind(char *cmd)
{
	char *pathvar = getenv("PATH");
	char pd[64], *pathd;
	char *ret = cmd;

	pathd = strtok(pathvar, ":");
	while (pathd)
	{
		_strcpy(pd, pathd);
		_strcat(pd, "/");
		if (file_exist(_strcat(pd, cmd)))
		{
		 	ret = _strdup(pd);
			break;
		}

		pathd = strtok(NULL, ":");
	}

	return (ret);
}

int file_exist(char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer) == 0);
}
