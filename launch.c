#include "hsh.h"

extern char **environ;

int launch(char **argv)
{
	pid_t pid;
	int status;
	char *cmd;
	char wd[1024];

	pid = fork();
	if (pid == 0)
	{
		if (strchr(argv[0], 47) == NULL)
			cmd = pathfind(argv[0]);
		else
			cmd = argv[0];
		if (execvp(cmd, argv) == -1)
			printf("%s: Command not found.\n", cmd);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("hsh");
	else
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return (1);
}
