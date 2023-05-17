
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


#define PRINTING(p) (write(STDOUT_FILENO, p, own_strlen(p)))
#define BUFSIZE 1024
#define PATH_MAXIMUM 1024

/**
 * struct builtin - Has builtin to handle
 * @command: Pointer to char
 * @fun: function to execute
 */

typedef struct builtin
{
	char *command;
	int (*fun)(char **buffer, int err);
} build_t;

/****Global variable***/
extern char **environ;

/***** FUNCTIONS FOUND IN FILE buildin.c *****/
void exit_buildin(char **cmd, char *inputi, char **argv, int k);
int disen(__attribute__((unused)) char **cmd, __attribute__((unused)) int prt);
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

/***** FUNCTIONS FOUND IN FILE bul_more.c *****/
int echo_print(char **cmd);
int disp_hist(__attribute__((unused))char **cm, __attribute__((unused))int s);


/***** FUNCTIONS FOUND IN FILE pet_fun.c *****/
void printing_error(char *command, int cntr, char **argv);
void fun_prompt(void);

/***** FUNCTIONS FOUND IN FILE shell.c *****/
int main(__attribute__((unused)) int arg_cnt, char **arg_v);
void env_create(char **envi);
int builtin_check(char **cmd);

/***** FUNCTIONS FOUND IN FILE exe.c *****/
void signal_handle(int sig_n);
int builtin_handle(char **cmd, int ere);
int cmd_check(char **cmd, char *buffer, int tc, char **arg_v);

/***** FUNCTIONS FOUND IN FILE exe_file.c *****/
void file_treat(char *buffer, int count, FILE *fp, char **arg_v);
void file_exit_bul(char **cmd, char *buffer, FILE *fil_d);
void file_read(char *filename, char **arg_v);

/***** FUNCTIONS FOUND IN FILE hist.c *****/
void envi_free(char **envi);
int buf_history(char *buffer);

/***** FUNCTIONS FOUND IN FILE out_put.c *****/
void print_error(char **arg_v, int cnt, char **cmd);

/***** FUNCTIONS FOUND IN FILE parser.c *****/
char **cmd_parse(char *buffer);

#endif
