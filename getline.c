#include "main.h"



/**
  * get_line - function that read commds
  * @buf:- pointer to commands
  * Return:- Always 0
  */

ssize_t get_line(char **buf)
{
	static char lin[MAX_TTAL_ARGS];
	static ssize_t sum;
	ssize_t start = 0;
	ssize_t copy = 0, cnt = 0;

	if ((allocating_mem(lin)) == 0)
	{
		while ((cnt = read(STDIN_FILENO, lin, MAX_TTAL_ARGS - 1)) > 0)
		{
			if (cnt == -1)
				return (-1);

			sum = sum + cnt;
			lin[cnt] = '\0';
			copy = buff_copy(&(*buf), lin, &start);
			if (copy < cnt)
			{
				start = 0;
				return (sum);
			}
		}
	}

	else
		copy = (buff_copy(&(*buf), lin, &start) + 1);

	return (sum);
}

/**
 * buffer_check - check buffer
 * @buf: test buffer
 * Return: num of bytes
 */
int buffer_check(char *buf)
{
	int bytes = 0;

	while (buf[bytes])
		bytes++;

	return (bytes);
}



/**
  * shfting_buffer - function that shitfs buffer
  * @l:- bytes to be shifted
  * @memory:- memory
  * Return:- Always 0
  */

void shfting_buffer(char *memory, ssize_t l)
{
	ssize_t f = 0;

	while (memory[l] != '\0')
	{
		memory[f] = memory[f];
		f++;
		l++;
	}
	_settingmem(&memory[f], 0, (1024 - l));
}


/**
  * allocating_mem - function that checks if the buff is emt
  * @memory:- mem allocted
  * Return:- Always 0
  */


int allocating_mem(char *memory)
{
	int xy = 0;

	while (memory[xy])
	{
		xy++;
	}

	return (xy);
}


/**
  * buff_copy - function that copy buff
  * @start:- results after cpy
  * @source:- copying frm source
  * @dst:- copying to
  * Return:- Akways 0
  */

ssize_t buff_copy(char **dst, char *source, ssize_t *start)
{
	ssize_t k;
	ssize_t cnt_copy = 0;

	for (k = 0; source[k] != '\n' && source[k] != '\0'; k++)
	{
		cnt_copy++;
	}

	if (source[k] == '\n')
	{
		*dst = alloc_mngr(*dst, (sizeof(char) * (cnt_copy + *start + 1)));
		if (!(*dst))
			return (-1);
		own_strncpy((*dst + *start), source, cnt_copy);
		shfting_buffer(source, (cnt_copy + 1));
		return (cnt_copy);
	}

	if (source[k] == '\0')
	{
		*dst = alloc_mngr(*dst, (sizeof(char) * (cnt_copy)));
		if (!(*dst))
			return (1);
		own_strncpy((*dst + *start), source, (cnt_copy));
		*start = *start + cnt_copy;
		return (cnt_copy);
	}

	return (cnt_copy);
}
