#include <sys/stat.h>
#include "hsh.h"
/**
 * *pathfind - finds the PATH of a command passed
 * @cmd: command
 * Return: ret
 */
char *pathfind(char *cmd)
{
	char *pathvar = _strdup(getvar("PATH")), *ret, pd[1024], *str = pathvar;
	struct stat sb;
	int i = _strcpos(pathvar, 58);

	if (i < 0)
	{
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
		_memset(pd, 0, sizeof(char) * 1024);
		_strncpy(pd, str, i);
		_strcat(pd, "/");
		if ((stat(_strcat(pd, cmd), &sb) == 0) && sb.st_mode & S_IXUSR)
		{
			ret = _strdup(pd);
			break;
		}
		for (; i >= 0; i--)
			str++;

		i = _strcpos(str, 58);
	}
	free(pathvar);

	return (ret);
}
