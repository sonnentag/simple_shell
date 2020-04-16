#include "hsh.h"
/**
 * launch - Forks parent process
 * @argv: pointer to a string of commands passed as arguments
 * Return: 0
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
		{
			cmd = pathfind(argv[0]);
			if (cmd == NULL)
			{
				perror("hsh: 1: ");
				return (147);
			}
		}
		else
			cmd = argv[0];
		if (execve(cmd, argv, envp) == -1)
			printf("%s: Command not found.\n", cmd);
		free(*argv);
		free(argv);
		exit(EXIT_FAILURE);
	}
	else
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	free(*argv);
	free(argv);

	return (0);
}
