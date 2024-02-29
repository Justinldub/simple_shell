#include "util.h"
#include "shell.h"
#include <dirent.h>


int ls(char **args)
{
	DIR *dir;
	struct dirent *entry;

	if((dir =opendir(".")) == NULL)
	{
		perror("could not list directory\n");
		exit(EXIT_FAILURE);
	}

	while((entry = readdir(dir)) != NULL)
	{
		printf("%s\n" ,entry -> d_name);
	}

	closedir(dir);

	return 1;
}
