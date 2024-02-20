#ifndef _UTIL_H
#define _UTIL_H

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int cd(char **args);
int help(char **args);
int exits(char **args);


#endif
