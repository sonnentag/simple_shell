#include <sys/stat.h>
#include "hsh.h"
/**
 * *pathfind - finds the PATH of a command passed
 * @cmd: command
 * Return: ret
 */
char *pathfind(char *cmd)
{
	char *pathvar = _strdup(getenv("PATH"));
	char pd[1024], *pathd;
	char *ret = cmd;

	pathd = strtok(pathvar, ":");
	while (pathd)
	{
		_strcpy(pd, pathd);
		strcat(pd, "/");
		if (file_exist(strcat(pd, cmd)))
			ret = _strdup(pd);

		pathd = strtok(NULL, ":");
	}
	return (ret);
}
/**
 * file_exist - checks if a file exist
 * @filename: name of file
 * Return: file status
 */
int file_exist(char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer) == 0);
}
