#include "shell.h"

/**
 * list_len - length linked list determined
 * @h: first node pointer
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
	h = h->next;
	num++;
	}
	return (num);
}

/**
 * list_to_strings - array of strings returned
 * @head: first node pointer
 *
 * Return: stringazrray
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t num = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !num)
	return (NULL);
	strs = malloc(sizeof(char *) * (num + 1));
	if (!strs)
	return (NULL);
	for (num = 0; node; node = node->next, num++)
	{
	str = malloc(_strlen(node->str) + 1);
	if (!str)
	{
	for (k = 0; k < num; k++)
	free(strs);
	}
	str = _strcpy(str, node->str);
	strs[num] = str;
	}
	strs[num] = NULL;
	return (strs);
}

/**
 * print_list - all element of list_t linked list printed
 * @h:  first node pointer
 *
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
	_puts(convert_number(h->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	h = h->next;
	num++;
	}
	return (num);
}

/**
 * node_starts_with - node whose string start with prefix returned
 * @node: list head  pointer
 * @prefix: string to match
 * @c: next character to  match after prefix
 *
 * Return: node or null match
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *q = NULL;

	while (node)
	{
	q = starts_with(node->str, prefix);
	if (q && ((c == -1) || (*q == c)))
	return (node);
	node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets index node
 * @head: list head pointer
 * @node: pointer to node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t num = 0;

	while (head)
	{
	if (head == node)
	return (num);
	head = head->next;
	num++;
	}
	return (-1);
}
