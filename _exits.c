#include "util.h"
/**
  * _exits - function that terminates the shell program
  * @args - command line arguments
  * Return: return 0 to quit the program loop and the program itself
  */
int _exits(char **args)
{
	if(args[1] == NULL)
		return (1);
	return 0;
}
