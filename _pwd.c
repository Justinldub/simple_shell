#include "shell.h"
#include "util.h"

int pwd(char **args)
{
	char path[4096];

	if(getcwd(path,sizeof(path)) != NULL)
	{
		printf("%s\n",path);
	}

	return 1;
}
