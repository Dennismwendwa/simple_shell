
#include "main.h"

/**
  * printing_error - function that prints error
  * @argv:- name of the running program
  * @cntr:- loop to count
  * @command:- the command the user enters
  * Return:- Always 0
  */

void printing_error(char *command, int cntr, char **argv)
{
	char *cat;

	PRINTING(argv[0]);
	PRINTING(": ");
	cat = own_itoa(cntr);

	PRINTING(cat);
	free(cat);

	PRINTING(": ");
	PRINTING(command);
	PRINTING(": not found\n");
}


/**
  * fun_prompt - function that prints prompt
  * Return:- Always 0
  */

void fun_prompt(void)
{
	PRINTING("$ ");

}
