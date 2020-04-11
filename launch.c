#include "hsh.h"

int launch(char **argv)
{
	pid_t pid;
	int status, rc;
	char *cmd, *destdir;
	char wd[1024];

	if (strcmp(argv[0], "cd") == 0)
	{
		destdir = argv[1];
		rc = chdir(destdir);

		if (rc) 
		{
			perror("chdir failed");
		}
		else 
		{

			setenv("PWD",destdir,1);
		}
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			/* Child process */
			cmd = pathfind(argv[0]);
			if (execvp(cmd, argv) == -1)
				printf("%s: Command not found.\n", cmd);

			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			/* Error handling */
			perror("hsh");
		}
		else
		{
			/* Parent process */
			do {
				pid = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}

	return (1);
}
