#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

/* Macros */
#define SUCCESS 0
#define FAILURE 1
#define br "----------------------------------------\n\n"
#define MAX_WORDS 100

/* Structures */

/* Prototypes */
char *get_pids(void);
char *pid_max(void);
char *read_line(void);
char **string_tokens(char *string);
int split_string(char *string, char *words[MAX_WORDS]);

#endif
