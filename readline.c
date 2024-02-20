#include "shell.h"
/*
 * read_line - function that reads command from the stdin using getline
 * Return: the command that was passed through the terminal
 */
char *read_line(void)
{
	/
	char *line = NULL;
	ssize_t bufsize = 0;
	if(getline(&line, &bufsize,stdin) == -1)
	{
		/*Check if CTRL + D was passed to the terminal*/
		if(feof(stdin))
		{
			/*Terminate the program with success*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline failed\n");
			exit(EXIT_FAILURE);
		}
	}
	/*return the command passed*/
	return line;
}
