#include "shell.h"
#include "util.h"

/*array for holding predefined command strings*/
char *builtin_str[] ={"cd", "help","exit"};
/*array to hold built in functioins*/
int (*builtin_func[]) (char **) ={&cd, &help, &_exits};
/*
 * num_builtins - function that returns number of builtin functions
 * Return: number of builtin functions
 */
int num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

/*
 * execute - function that execute the launch program based on the argument passed
 * Return: a function that launches a child program that execute shell command
 */
int execute(char **args)
{
	
	int i;
	/*Check if args are null return 1 the status code that tells the loop to continue to run*/
	if(args[0] == NULL)
	return 1;

	for(i = 0; i < num_builtins(); i++)
	{
		/*if args at 0 correspond to the builtin function return the index of that function which will be executed on launch*/
		if(strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
	}
	return launch(args);
}
