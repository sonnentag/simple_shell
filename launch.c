#include "hsh.h"

/**
 *
 *
 */
int launch(char **argv)
{
	pid_t pid;
	int status;
	char *cmd;
	char **envp = environ;

	pid = fork();
	if (pid < 0)
		perror("hsh");
	if (pid == 0)
	{
		if (strchr(argv[0], 47) == NULL)
			cmd = pathfind(argv[0]);
		else
			cmd = argv[0];
		if (execve(cmd, argv, envp) == -1)
			printf("%s: Command not found.\n", cmd);
		free(argv);
		exit(EXIT_FAILURE);
	}
	else
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	free(argv);

	return (0);
}
