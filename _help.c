#include "util.h"
#include "shell.h"

char *builtin_st[] ={"cd", "help","_exits"};

/**
  * help - function that prints help into the terminal
  * @args - command line args
  * Return: Always 1 to continue the loop
  */
int help()
{
	int i;
	
	printf("ALX shell v.1.0.0\n");
	printf("Type program names and arguments, and hit enter\n");
	printf("Available builtin commands\n");
	for (int i = 0; i < num_builtins();i++)
	{	
		printf("%s\n",builtin_st[i]);
	}
	return (1);
}
