#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void shell(void);
ssize_t read_cmd(char **line, size_t *len);
int _strtok(char *line, char **arg);
void _path(char *bin, char *path, char **full);
int run(char **arg, char *full, char *line);
void h_exit(char *arg[], char *str, int status_exit);
ssize_t _write(char **line, size_t *len);
void envar(void);

#endif
