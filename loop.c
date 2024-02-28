#include "shell.h"
/*
 * loop - funtion that displays prompt, and initiate a loop
 * Return: return nothing
 */
void loop(void)
{
	/* a command string */
	char* line;
	/* array of string broken down in tokens */
	char **args;
	/* the status of the program when it is running for error handling purposes */
	int status;

	
	do{

		/*Display prompt to the terminal*/
		printf("$");
		/*Reading command from the stdin*/
		line = read_line();
		/*split the command into tokens*/
		args = split_line(line);
		/*finally execute the command*/
		status = execute(args);
		
		/*Cleaning garbage*/
		free(line);
		free(args);

	}
	while(status); /*While the status is not of error or exit continue to loop */
}
