
#include "main.h"

/**
  * getline - function that read commds
  * @buf:- pointer to commands
  * Return:- Always 0
  */

ssize_t get_line(char **buf)
{
	static char lin[MAX_TTAL_ ARGS];
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
			copy = buff_copy(&(*buf), lin, &begin);
			if (copy < cnt)
			{
				start = 0;
				return (sum);
			}
		}
	}

	else
		copy = (buff_copy(&(*buf), lin, &begin) + 1);

	return (sum);
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
	settingmemory(&memory[f], 0, (1024 - l));
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
		*dst = manenger_allc(*dst, (sizeof(char) * (cnt_copy + *start + 1)));
		if (!(*dst))
			return (-1);
		own_strncpy((*dst + *start), source, cnt_copy);
		shift_buffer(source, (cnt_copy + 1));
		return (cnt_copy);
	}

	if (source[k] == '\0')
	{
		*dst = manenger_allc(*dst, (sizeof(char) * (cnt_copy)));
		if (!(*dst))
			return (1);
		own_strncpy((*dst + *start), source, (cnt_copy));
		*start = *start + cnt_copy;
		return (cnt_copy);
	}

	return (cnt_copy);
}













































/**
  * get_line - function that reads commandline inputs
  * Return:- Always 0
  */

char *get_line() /* not in use */
{
	char k = 0;
	int buffersize = BUFFERSIZE, readd;
	char *buffer = malloc(buffersize);
	int j;

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (j = 0; k != EOF && k != '\n'; k++)
	{
		fflush(stdin);
		readd = read(STDIN_FILENO, &k, 1);

		if (readd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[j] = k;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}

		if (j >= buffersize)
		{
			buffer = _reallocc(buffer, buffersize, buffersize + 1);
			if (buffer == NULL)
				return (NULL);
		}
	}

	buffer[j] = '\0';
	hundle_hashtag(buffer);
	return (buffer);


	int j = 0;

	for (; buffer[j] != '\0'; j++)
	{
		if (buffer[j] == '#')
		{
			buffer[j] = '\0';
			break;
		}
	}
}

