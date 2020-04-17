#include "hsh.h"

/**
 * getvar - get variable from environment
 * @vname: var name to get
 * Return: null
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
