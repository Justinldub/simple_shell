#include "shell.h"
#define BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

char **split_line(char *line)
{
	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize *sizeof(char*));
	char *token, **tokens_backup;

	if(!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIM);
	while(token != NULL)
	{
		tokens[position] = token;
		position++;
	}

	if(position >= bufsize)
	{
		bufsize += BUFSIZE;
		tokens_backup = tokens;
		tokens = realloc(tokens, bufsize *sizeof(char*));
		if(!tokens)
		{
			free(tokens_backup);
			fprintf(stderr, "allocation error\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
