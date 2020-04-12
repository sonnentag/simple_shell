#include <sys/stat.h>
#include "hsh.h"

char *pathfind(char *cmd)
{
<<<<<<< HEAD
	char *pathvar = getenv("PATH");
	char pd[64], *pathd;
=======
	char *pathvar = getenv("PWD");
 	char pd[64], *pathd;
>>>>>>> 1576705be348f68f86c5d6068a44bcdaf2b5ee0d
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
