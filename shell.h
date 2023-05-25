#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char **environ;

void display_prompt(void);
int check_command_exists(const char *command);
void print_environment(void);

#endif
