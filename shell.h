#ifndef SIMPLE_SHELL_SHELL_H
#define SIMPLE_SHELL_SHELL_H

#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

char *copy_line(void);
char **cut_string(char *buffer);
void shell_execute(char **command);
char *copy_getchar(void);
void signal_handler(int sig);

#endif
