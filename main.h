
#ifndef MAIN_H
#define MAIN_H

#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>


#define PRINTING(p) (write(STDOUT_FILENO, P, own_strlen(p)))

#define PATH_MAXIMUM 1024


/***** FUNCTIONS FOUND IN FILE buildin.c *****/
void exit_buildin(char **cmd, char *inputi, char **argv, int k);
int display_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int print);
int dir_change(char **cmd, __attribute__((unused))int print);
int bul_echo(char **cmd, int start);
int help_display(char **cmd, __attribute__((unused)) int print);


/***** FUNCTIONS FOUND IN FILE fun_chars.c *****/
int own_strlen(char *x);
int own_atoi(char *x);
int _putchar(char k);
char *own_strncpy(char *kwenda, char *kbq, int l);
void _putts(char *kbq);


/***** FUNCTIONS FOUND IN FILE getline.c *****/
char *get_line();
void hundle_hashtag(char *buffer);


/***** FUNCTIONS FOUND IN FILE memory_mngr.c *****/
void *_kalloc(unsigned int s);
void *filling_array(void *kim, int num, unsigned int size);
char memorycpy(char *dst, char *source, unsigned int k);
void freeing_all(char **kbq, char *linne);
void _reallocc(void *pointer, unsigned int oldersize, unsigned int newersize);


/***** FUNCTIONS FOUND IN FILE number_prnt.c *****/
void numberin_print(int a);
void num_print(unsigned int j);


/***** FUNCTIONS FOUND IN FILE other_char_funs.c *****/
void rev_arry(char *ar, int length);
int own_intlen(int number);
char *own_itoa(unsigned int l);
int own_isalpha(int f);
int own_strcmp(char *sizeone, char *sizetwo);


/***** FUNCTIONS FOUND IN FILE own_strtoken.c *****/
unsigned int delim_check(char g, const char *string);
char *own_strtok(char *string, const char *sep);


/***** FUNCTIONS FOUND IN FILE path_finder.c *****/
char *_getenv(char *nickname);
int pathh_cmd(char **input);
char *building(char *words, char *volum);


/***** FUNCTIONS FOUND IN FILE pet_fun.c *****/
void printing_error(char *command, int cntr, char **argv);
void fun_prompt(void);































#endif
