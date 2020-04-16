#include <sys/stat.h>
#include "hsh.h"
/**
 * *pathfind - finds the PATH of a command passed
 * @cmd: command
 * Return: ret
 */
char *pathfind(char *cmd)
{
	char *ret, pd[1024], *str = pathvar, *pathvar = _strdup(getenv("PATH"));
	struct stat sb;
	int i = _strcpos(pathvar);

	if (i < 0)
	{
<<<<<<< HEAD
		_strcpy(pd, pathd);
		strcat(pd, "/");
		if (file_exist(strcat(pd, cmd)))
			ret = _strdup(pd);
=======
		_strcat(pathvar, "/");
		if ((stat(_strcat(pathvar, cmd), &sb) == 0) && sb.st_mode & S_IXUSR)
			ret = _strdup(pd);
	}
	while (i >= 0)
	{
		if (i == 0)
			if ((stat(cmd, &sb) == 0) && sb.st_mode & S_IXUSR)
			{
				ret = _strdup(cmd);
				break;
			}
		memset(pd, 0, sizeof(char) * 1024);
		_strncpy(pd, str, i);
		_strcat(pd, "/");
		if ((stat(_strcat(pd, cmd), &sb) == 0) && sb.st_mode & S_IXUSR)
		{
			ret = _strdup(pd);
			break;
		}
		for (; i >= 0; i--)
			str++;
>>>>>>> 51407317fdc94916907a080eacaac5c400946f4a

		i = _strcpos(str);
	}
	free(pathvar);

	return (ret);
}
<<<<<<< HEAD
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
=======

>>>>>>> 51407317fdc94916907a080eacaac5c400946f4a
