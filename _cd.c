#include "util.h"
#include "shell.h"
/*
 * cd - function that changes the current working directory 
 * to the specified one
 * @args - command line argumments
 * Return: 1 to continue the loop after the command is executed
 */
int cd(char **args)
{
	if (args[1] == NULL)
	{
		printf("Error on reading command");
		fprintf(stderr, "expected argument");
	}
	else
	{
		/*Check if the specified directory is available*/
		if (chdir(args[1]) != 0)
			perror("invalid command");
	}
	/*Return 1 to continue the loop*/
	return (1);
}
