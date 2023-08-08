![holberton_name 01](https://github.com/michaellgans/holbertonschool-simple_shell/assets/126801159/7242fb14-8882-4d04-83d7-68badd5463f7)
# Simple_Shell 


## Introduction
> Hey there! :alien:<br>
Thanks for checking out our Simple Shell Project. Here we have constructed our own Simple Shell that emulates the _Bourne Again Shell_.<br>
Our Simple Shell is programmed to handle two built-in functions, which are `env` and `exit`. It is also programmed to be able to interperate commands in path with and without options such as `ls` or  `ls -a -l`.<br>
We appreicate your interest in this project and we would appreicate any feedback you could give us!

## What is a shell?
A shell is a program that provides a command-line interface for users to interact with the computer's operating system. It allows users to execute commands and run programs by typing text commands.

## Project Requirements
<details>
<summary>General</summary>
<br>

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the option `Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl)
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
</details>

<details>
<summary>Allowed Functions & System Calls</summary>
<br>
   | |
|----------|----------|
|all functions from strings.h|
|access (man 2 access)|
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)
</details>

## How to download
- Go to [this link](https://github.com/michaellgans/holbertonschool-simple_shell/tree/main)

- Download files or copy the clone URL

<img src="https://github.com/michaellgans/holbertonschool-simple_shell/assets/126801159/2000dcfb-498b-4f79-81d5-a048fca9bd57" width="50%" height="auto">

***

## How to use program
### Flowchart
![flowchart_process_SHELL](https://github.com/michaellgans/holbertonschool-simple_shell/assets/126801159/bb039cd2-ec91-4f56-b79c-be9333d1ca32)

### Compiler
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

***

## Program Contents

  File|Prototype|Description|
|----------|----------|-----------|
|[simple_shell.c](https://github.com/michaellgans/holbertonschool-simple_shell/blob/main/README.md)|`int main(int argc, char **argv, char **env)`|Main function
|[tokenize.c](https://github.com/michaellgans/holbertonschool-simple_shell/blob/main/tokenize.c)|`int tok_num(char *str, char *delims)` `char **tokstr(char *line, char *delims)` `int substrLen(char *str, char *delims)`|Sections input for processing the called command| 
|[find_path.c](https://github.com/michaellgans/holbertonschool-simple_shell/blob/main/find_path.c)|`int find_path(char **path_array, char **args_array)`|Directs operating system to called command|
|[execute_program.c](https://github.com/michaellgans/holbertonschool-simple_shell/blob/main/execute_program.c)|`int execute_program(char *op_path, char **string_array)`|Executes the called command|
|[free_helper.c](https://github.com/michaellgans/holbertonschool-simple_shell/blob/main/free_helper.c)|`void free_string_array(char **array)` `void free_string(char *str)` `int free_the_mems(char **tokens_array, char **path_array)`|Deallocates memory|
|[main.h](https://github.com/michaellgans/holbertonschool-simple_shell/blob/main/main.h)|Includes libraries, macros, and prototypes|Header file that provides futher instructions for program|

Created by [Michael Gans](https://github.com/michaellgans) & [Jess Dison](https://github.com/jessasesh)

