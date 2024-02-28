#include "shell.h"
#define BUFSIZE 64 /*The size of the buffer to hold the passed command string*/
#define TOKEN_DELIM " \t\r\n\a" /*the token delinitors used to process special charactors in a string*/
/**
  * spli_line - function that takes the passed input from the terminal and brake it into tokens for further analyzing
  * args - a string to be tokenized
  * Return - a string broken into tokens
  */
char **split_line(char *line)
{

	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

	if(!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	/*Braking the string into tokens*/
	token = strtok(line, TOKEN_DELIM);
	while(token != NULL)
	{
		/*aligning the first token to the 1st position*/
		tokens[position] = token;
		/*Moving to the next position to align with the next token*/
		position++;

		if(position >= bufsize)
		{
			/*increase the buffer to hold as needed*/
			bufsize += BUFSIZE;
			/*inserting tokens into backup*/
			tokens_backup = tokens;
			/*reallocating memory into tokens array*/
			tokens = realloc(tokens, bufsize *sizeof(char*));
			if(!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}

		}
			token = strtok(NULL, TOKEN_DELIM);

	}

	tokens[position] = NULL;
	return tokens;
}
