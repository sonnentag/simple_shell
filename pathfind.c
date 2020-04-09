#include <sys/stat.h>
#include "hsh.h"

char *pathfind(char *cmd)
{
	char pathvar[] = "/home/asims/.bin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
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
printf("%s\n", ret);
	return (ret);
}

int file_exist(char *filename)
{
	struct stat buffer;   

	return (stat (filename, &buffer) == 0);
}
