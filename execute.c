#include "shell.h"
#include "util.h"

char *builtin_str[] ={"cd", "help","_exits"};

int (*builtin_func[]) (char **) ={&cd, &help, &_exits};

int num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}


int execute(char **args)
{
	

	int i;

	if(args[0] == NULL)
	return 1;

	for(i = 0; i < num_builtins(); i++)
	{
		if(strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
	}


	return launch(args);
}
