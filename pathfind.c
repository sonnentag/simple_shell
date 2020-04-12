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
		strcpy(pd, pathd);
		strcat(pd, "/");
		if (file_exist(strcat(pd, cmd)))
		{
			ret = strdup(pd);
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
