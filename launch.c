#include "shell.h"

int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if(pid == 0)
	{
		/*child process*/
		if(execvp(args[0], args) == -1)
		{
			perror("shell error");
		}
		exit(EXIT_FAILURE);

	}
	else if(pid < 0)
	{
		perror("unable to fork");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
