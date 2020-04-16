#include "hsh.h"

char *getvar(char *vname)
{
        char **envp;
        char *vval, *vcmp; 
        int c = 0;

        envp = environ;
        while (*envp)
        {
                vval = strdup(envp[c]);
                vcmp = strtok(vval, "=");
		while (vcmp)
		{
			vcmp = strtok(NULL, "=");
			if (strcmp(vval, vname) == 0)
				return (vcmp);
		}
                *envp++;
        }

        return (NULL);
}

