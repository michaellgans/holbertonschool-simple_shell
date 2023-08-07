#include "main.h"

/**
 * main - the main function that houses simple shell.
 * @argc: number of arguments.
 * @argv: array of pointers to the arguments
 * @env: array of pointers to the environmental variables.
 * Return: SUCCESS/FAILURE (0/1)
 */
int main(int argc, char **argv, char **env)
{
    char **tokens_array = NULL, **path_array = NULL; /* array of tokens */
    size_t length = 0; /* length of what was read */
    int x = 0, operation = 0; /* iterations */
    char *line = NULL, *path = NULL; /* what was read, beginning of path*/
    (void)argc;
    (void)argv;

    while (true) /* Infinite loop that keeps the prog running */
    {
        /* Interactive (person) or Non-Interactive (program) */
        if (isatty(STDIN_FILENO))
            printf("$: "); /* Display cursor if person */

        /* Get input from user */
        if (getline(&line, &length, stdin) == -1)
        {
            break;
        }
        cleanstr(line); /* Remove newline char */
        if (!tok_num(line, " ")) /* Check for empty line */
            continue;
        tokens_array = tokstr(line, WHITESPACE1);

        /* Is the command a built-in function? */
        if (strcmp(tokens_array[0], "env") == 0)
        {
            for (x = 0; env[x] != NULL; x++)
            {
                printf("%s\n", env[x]);
            }
            free_string_array(tokens_array);
            continue;
        }

        if (strcmp(tokens_array[0], "exit") == 0)
        {
            free_string_array(tokens_array);
            break;
        }
        x = 0;

        while (env[x] != NULL) /* Check for path given */
        {
            if (strncmp(env[x], "PATH=", 5) == 0)
            {
                path = strdup((env[x] + 5)); /* store first 5 char */
                break;
            }
            x++;
        }
        path_array = tokstr(path, WHITESPACE2);
        free(path);

        /* Check for access */
        if (access(tokens_array[0], X_OK) == 0)
        {
            execute_program(tokens_array[0], tokens_array);
        }
        else
        {
            operation = find_path(path_array, tokens_array);
        }
        free_string_array(tokens_array);
        free_string_array(path_array);
    }
    if (line)
        free(line);
    return (operation);
}
