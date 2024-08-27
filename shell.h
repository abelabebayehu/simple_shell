#ifndef SHELL_H
#define SHELL_H

extern char **environ;

void execute_command(char *line);
void prompt(void);

#endif /* SHELL_H */
