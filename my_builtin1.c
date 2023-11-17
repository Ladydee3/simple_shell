#include "shell.h"

/**
 * _myalias - minics the builtin alias (man alias)
 * @info: structure containing potetial arguments
 * Return: 0 always
 */
int _myalias(info_t *info)
{
	int num = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
	node = info->alias;
	while (node)
	{
	print_list(node);
	node = node->next;
	}
	return (0);
	}
	for (num = 1; info->argv[num]; num++)
	{
	q = _strchr(info->argv[num], '=');
	if (q)
	
	print_list(node_starts_with(info->alias, info->argv[num], '='));
	}
	return (0);
}

/**
 * _myhistory - history list displayed, commanded buy line
 *             preceded with line bstarting with 0
 *  @info: structure containing potetial argument
 *  Return: 0 always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - string alias set
 * @info: struct parameter
 * @str: aslias string
 *
 * Return: 1 on error, 0 on success
 */
int unset_alias(info_t *info, char *str)
{
	char *q, c;
	int ret;

	q = _strchr(str, '=');
	if (!q)
	return (1);
	c = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = c;
	return (ret);
}


/**
 * set_alias - alias string set
 * @info: struct parameter
 * @str: alias string
 *
 * Return: 1 on error, 0 on success
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
	return (1);
	if (!*++q)
	return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - printed alias string
 * @node: alias node
 *
 * Return: 0 on success , 1 on error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *d = NULL;

	if (node)
	{
	q = _strchr(node->str, '=');
	for (d = node->str; d <= q; d++)
	_putchar(*d);
	_putchar('\'');
	_puts(q + 1);
	_puts("'\n");
	return (0);
	}
	return (1);
}

