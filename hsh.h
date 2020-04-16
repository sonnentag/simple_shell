#ifndef _HSH_H
#define _HSH_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

int builtincmd(char **argv);
void sigintHandler(int sig);
char *getvar(char *vname);
int launch(char **args);
char *pathfind(char *cmd);
char *read_line(void);
char **split_line(char *line);

char *_memset(char *s, char b, unsigned int n);
int _strcmp(char *s1, char *s2);
int _strcpos(char *path);
char *_strncpy(char *dest, char *src, int n);
char *_strncatn(char *str, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);

#endif /* _HSH_H */
