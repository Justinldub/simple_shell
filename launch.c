#include "shell.h"
/*
 * launch - function that loads and launches another program and execute it using execvp
 * Return: The status code while the shell is running. 1 for success, 0 to exit the shell -1 for error
 */
int launch(char **args)
{
	/*Process ID for programs*/
	pid_t pid;
	/*The status of the program */
	int status;

	/*Forking process ID and creating a child process*/
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
		/*Child process not created forking failed*/
		perror("unable to fork");
	}
	else
	{
		do
		{
			/*Wait for the launched program to finish executing, terminate it and head back to parent process*/
			waitpid(pid, &status, WUNTRACED);
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
