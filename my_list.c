#include "shell.h"

/**
 * add_node_end - node added to to the end of list
 * @str: str node field
 * @head: head node pointer address
 * @num: index node used by history
 *
 * Return: list size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
	return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
	return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
	new_node->str = _strmap(str);
	if (!new_node->str)
	{
	free(new_node->str);
	return (NULL);
	}
	}
	if (node)
	{
	while (node->str)
	node = node->next;
	node->next = new_node;
	}
	else
	*head = new_node;
	return (new_node);
}

/**
 * add_node - node added to the start of the list
 * @head: head node pointer address
 * @str: str node field
 * @num: index node used by history
 *
 * Return: list size
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
	return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
	return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
	new_head->str = _strmap(str);
	if (!new_head->str)
	{
	free(new_head);
	return (NULL);
	}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * print_list_str - prints only the str element of a list_t link list
 * @h: first node pointer
 *
 * Return: list of size
 */
size_t print_list_str(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	h = h->next;
	num++;
	}
	return (num);
}

/**
 * delete_node_at_index - node at given index deleted
 * @head: first node pointer address
 * @index: index of node to delete
 *
 * Return: on success 1, on failure 0
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int num = 0;

	if (!index || !*head)
	return (0);

	if (!index)
	{
	node = *head;
	*head = (*head)->next;
	free(node->str);
	free(node);
	return (1);
	}
	node = *head;
	while (node)
	{
	if (num == index)
	{
	prev_node->next = node->next;
	free(node->str);
	free(node);
	return (1);
	}
	num++;
	prev_node = node;
	node = node->next;
	}
	return (0);
}

/**
 * free_list - all node of a list freed
 * @head_ptr: pointer address to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
	return;
	head = *head_ptr;
	node = head;
	while (node)
	{
	next_node = node->next;
	free(node->str);
	free(node);
	node = next_node;
	}
	*head_ptr = NULL;
}
