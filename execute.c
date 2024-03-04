#include "shell.h"
#include "util.h"

/*array for holding predefined command strings*/
char *builtin_str[] ={"cd", "help","exit", "pwd", "ls", "env"};
char *func_args_str[] = {"ls-l"};
/*array to hold built in functioins*/
int (*builtin_func[]) (char **) ={&cd, &help, &_exits, &pwd, &ls, &env};
int (*func_args[]) (char **) = {&ls_l};

/**
  * num_builtins - function that returns number of builtin functions
  * Return: number of builtin functions
  */
int num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}
int num_func_args()
{
	return sizeof(func_args_str) / sizeof(char *);
}
/**
  * execute - function that execute the launch program based on the argument passed
  * args - args for the program to be executed
  * Return: a function that launches a child program that execute shell command
  */
int execute(char **args)
{

	int i;
	char *path;
	char *path_copy;
	char *dir;

	/*Check if args are null return 1 the status code that tells the loop to continue to run*/
	if (args[0] == NULL)
	return (1);

	for (i = 0; i < num_builtins(); i++)
	{
		
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i])(args);
		}
	}
			path = getenv("PATH");
			if (path == NULL)
			{
				fprintf(stderr, "Error: PATH environment variable not set\n");
				exit(EXIT_FAILURE);
			}
			
			path_copy = strdup(path);
			dir = strtok(path_copy, ":");
			while(dir != NULL)
			{
				char command_path[1024];
				snprintf(command_path, sizeof(command_path), "%s/%s", dir, args[0]);
				if(access(command_path, X_OK) == 0)
					return launch(args);
					dir = strtok(NULL, ":");
			}
			fprintf(stderr,"Command was not found %s\n",args[0]); 
	return (1);
}
