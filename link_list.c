#include "main.h"

/**
 * alias_add_end - Adds a node to alias_t linked list.
 * @value: value of new alias added.
 * @head: a pointer to head of list
 * @name: name of new alias
 * Return: If fail NULL
 */

_aliast *alias_add_end(_aliast **head, char *name, char *value)
{
	_aliast *last;
	_aliast *nw_node = malloc(sizeof(_aliast));

	if (!nw_node)
		return (NULL);

	nw_node->next = NULL;
	nw_node->name = malloc(sizeof(char) * (own_strlen(name) + 1));
	if (!nw_node->name)
	{
		free(nw_node);
		return (NULL);
	}
	nw_node->value = value;
	own_strcpy(nw_node->name, name);

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = nw_node;
	}
	else
	{
		*head = nw_node;
	}
	return (nw_node);
}

/**
 * node_add_end - add node to end of list_t
 * @hd: A pointer to the head of list
 * @dir: The dir path for new node
 * Return: NULL if fail
 */
list_t *node_add_end(list_t **hd, char *dir)
{
	list_t *last;
	list_t *nw_node = malloc(sizeof(list_t));

	if (!nw_node)
		return (NULL);

	nw_node->dir = dir;
	new_node->next = NULL;

	if (*hd)
	{
		last = *hd;
		while (last->next != NULL)
			last = last->next;
		last->next = nw_node;
	}
	else
		*hd = nw_node;

	return (nw_node);
}

/**
 * freeing_alias_ls - free _aliast linked list
 * @hd: head of list
 */
void freeing_alias_ls(_aliast *head)
{
	_aliast *next;

	while (hd)
	{
		next = hd->next;
		free(hd->name);
		free(hd->value);
		free(hd);
		hd = next;
	}
}

/**
 * list_free - free list_t linked list
 * @head: head of list
 */
void list_free(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
