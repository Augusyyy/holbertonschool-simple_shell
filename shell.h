#ifndef SIMPLE_SHELL_SHELL_H
#define SIMPLE_SHELL_SHELL_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *copy_line(void);
char **cut_string(char *buffer);
void shell_execute(char **command);
char *copy_getchar(void);
void signal_handler(int sig);

#endif //SIMPLE_SHELL_SHELL_H
