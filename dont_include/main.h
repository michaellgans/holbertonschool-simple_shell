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
#include <sys/stat.h>

/* Macros */
#define SUCCESS 0
#define FAILURE 1
#define br "----------------------------------------\n\n"
#define WHITESPACE1 " \n\t"
#define WHITESPACE2 ":"

/* Prototypes */
void free_string_array(char **array);
int execute_program(char *op_path, char **string_array);
int find_path(char **path_array, char **args_array);
int cleanstr(char *line);
int tok_num(char *str, char *delims);
char **tokstr(char *line, char *delims);
int substrLen(char *str, char *delims);
char **tokenize(char *string);

#endif
