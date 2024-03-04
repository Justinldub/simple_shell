#include "shell.h"
#include "util.h"
/**
  * env - function that prints the current environment
  * @args - command line arguments
  * Return: return 1 to continue to loop
  */
int env() 
{
	char **env;
	env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return (1);
}
