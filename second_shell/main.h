
#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdarg.h>
#include <limits.h>
#include <dirent.h>
#include <errno.h>


/***** ENV *****/
extern char **environ;


/***** FUNCTIONS FROM FILE built.c *****/
int checkbuilt(char *lin, char **arrs, char *nwlin, char **arry_token);
void changing_dir(char **arrs);


/***** FUNCTIONS FROM FILE more_str.c *****/
int _putchar(char c);
int prstring(va_list *args);
void _putts(char *string);


/***** FUNCTIONS FROM FILE persing.c ****/
void mine_free(char *lin, char **arrs, char *nwlin, char **arry);
int parsing(char *lin, int number_tok, char **argv, int coutcmd);


/***** FUNCTIONS FROM FILE str_tools.c *****/
char *own_strdup(char *string);
int number_count(char *lin);
char *own_strcat(char *dst, char *source);
int own_strncmp(char *stringone, char *stringtwo, int length);
int own_strcmp(char *stringone, char *stringtwo);


/***** FUNCTIONS FROM FILE exe.c *****/
int exe(char *buffer, char **ar, char *dpl, char **tok, char **argv, int fcnt);


/***** FUNCTIONS FROM FILE print.c *****/
int check_format(va_list *arg_p, const char *format, int j);
void get_digit(int m);
int print_f(const char *format, ...);
int print_digit(va_list *arg_s);


/***** FUNCTIONS FROM FILE path_func.c *****/
int find_path(char **toks);
char *own_strcpy(char *dest, char *src);
void path_exe(char *p, char **toks);
int path_search(char *p, char **toks);

/***** FUNCTIONS FROM FILE shell.c *****/
int main(int arg_c, char *arg_v[]);


/**
  * struct fmt - furnction data
  * @ltr: data type
  * @type: ptr of func type
  */

typedef struct fmt
{
	char *ltr;
	int (*type)();
} fmt;

#endif