#include "hsh.h"
/**
 * *getvar - get environment variable
 * @vname: variable name
 * Return: NULL
 */
char *getvar(char *vname)
{
	char **envp;
	char *vval, *vcmp;
	int c = 0;

	envp = environ;
	while (*envp++)
	{
		vval = _strdup(envp[c]);
		vcmp = strtok(vval, "=");
		while (vcmp)
		{
			vcmp = strtok(NULL, "=");
			if (_strcmp(vval, vname) == 0)
				return (vcmp);
		}
	}

	return (NULL);
}
