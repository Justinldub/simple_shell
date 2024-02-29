#include "shell.h"
#include "util.h"
/**
  * pwd - function that prints the current working directory
  * @args - the command line arguments
  * Return: 1 to continue looping the program
  */
int pwd(char **args)
{
	char path[4096];

	if(getcwd(path,sizeof(path)) != NULL)
	{
		printf("%s\n",path);
	}

	return 1;
}
