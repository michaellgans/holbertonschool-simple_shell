#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

/* Macros */
#define SUCCESS 0
#define FAILURE 1
#define br "----------------------------------------\n\n"
#define WHITESPACE1 " \n\t"
#define WHITESPACE2 ":"

/* Structures */

/* Prototypes */
/* char *get_pids(void); */
/* char *pid_max(void); */
/* char *read_line(void); */
char **tokenize(char *string, char *delimiters, char **tokens_array);
int execute_program(void);
/* void builtin_exit(char **args); */
/* void builtin_env(char **args); */
/* void find_builtin(char **args); */

#endif
