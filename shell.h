#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void display_prompt(void);
char *read_input(void);
int execute_command(char *command, char **envp);

#endif /* SHELL_H */
