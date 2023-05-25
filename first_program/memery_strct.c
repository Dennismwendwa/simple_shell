
#include "main.h"

/**
  * _settingmem - function thst sets memory
  * @k:- number of bytes
  * @c:- bytes const
  * @j:- ptr location to set
  * Return:- Always 0
  */

char *_settingmem(char *j, char c, unsigned int k)
{
	unsigned int x = 0;

	while (x < k)
	{
		j[x] = c;
		x++;
	}


	return (j);
}

/**
  * own_realloc - function that alloctsmem
  * @sizenw:- new size of mem
  * @pointer:- prviours alloc
  * Return:- Always 0
  */

char *own_realloc(char *pointer, size_t sizenw)
{
	size_t j = 0;
	size_t sizeod = own_strlen(pointer);
	char *repointer;

	if (sizenw == sizeod)
		return (pointer);

	if (sizenw == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	repointer = malloc(sizenw);
	if (!repointer)
	{
		return (pointer);
	}

	if (pointer)
	{
		for (j = 0; j < sizeod && j < sizenw; j++)
		{
			*(repointer + j) = *(pointer + j);
		}

	}
	_settingmem((repointer + sizeod), 0, (sizenw - sizeod));

	return (repointer);
}

/**
  * freeing_memlst - function that frees mem
  * @head:- ptr to strct
  */

void freeing_memlst(mem_list **head)
{
	mem_list *pmt;

	if (head)
	{
		while (*head)
		{
			pmt = *head;
			*head = (*head)->next;

			if (pmt->mem_ptr)
			{
				free(pmt->mem_ptr);
			}
			free(pmt);
		}

		*head = NULL;
	}
}

/**
  * add_memnode - function that lnks nodes
  * @pointer:- pointer fr nw node
  * @head:- head to lst
  * Return:- Always 0
  */

mem_list *add_memnode(mem_list **head, char *pointer)
{
	mem_list *nw;

	nw = malloc(sizeof(mem_list));

	if (!nw)
		return (NULL);

	nw->mem_ptr = pointer;
	nw->next = *head;

	*head = nw;

	return (*head);
}

/**
  * alloc_mngr - function that that alloc spac for mem
  * @pointer:- pointer to new mem
  * @siz:- needed siz
  * Return:- Always 0
  */



char *alloc_mngr(char *pointer, size_t siz)
{
	pointer = own_realloc(pointer, siz);

	if (!(pointer))
	{
		perror("hsh");
		freeing_memlst(&mem_head);
		return (NULL);
	}

	mem_head = add_memnode(&mem_head, pointer);

	return (pointer);
}
