#ifndef _HSH_H
#define _HSH_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 
 * const struct varinit varinit[] = {
 *       {&vifs,   VSTRFIXED|VTEXTFIXED,           "IFS= \t\n"},
 *       {&vpath,  VSTRFIXED|VTEXTFIXED,           "PATH=:/bin:/usr/bin"},
 *       {&vps1,   VSTRFIXED|VTEXTFIXED,           "PS1= ($) "},
 *       {&vvers,  VSTRFIXED|VTEXTFIXED,           "SHELLVERS=_sh 0.1alpha"},
 *       {NULL,    0,                              NULL}
 * };
 */

char *read_line(void);
char **split_line(char *line);
int launch(char **args);
int file_exist(char *filename);
char *pathfind(char *cmd);

#endif
