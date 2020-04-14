#ifndef _HSH_H
#define _HSH_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

char *read_line(void);
char **split_line(char *line);
int launch(char **args);
int file_exist(char *filename);
char *pathfind(char *cmd);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int builtincmd(char **argv);
void sigintHandler(int sig);

#endif
