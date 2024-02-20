#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/times.h>
#include <sys/wait.h>

/*
 * Core system functions
 */
void loop(void);
int launch(char **args);
int execute(char **args);
char *read_line(void);
char ** split_line(char *line);

#endif
