#include "hsh.h"
/**
 * launch - Forks parent process
 * @argv: pointer to a string of commands passed as arguments
 * @cnt: command count
 * Return: 0
 */
int launch(char **argv, int cnt)
{
	pid_t pid;
	int status;
	char *cmd;
	char **envp = environ;

	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (_strchr(argv[0], 47) == NULL)
		{
			cmd = pathfind(argv[0]);
			if (cmd == NULL)
			{
				_perrmsg(argv, cnt);
				exit(EXIT_FAILURE);
			}
		}
		else
			cmd = argv[0];
		if (execve(cmd, argv, envp) == -1)
			_perrmsg(argv, cnt);
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
