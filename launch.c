#include "hsh.h"

int launch(char **argv)
{
	pid_t pid, wpid;
	int status;
	char *cmd;

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
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
