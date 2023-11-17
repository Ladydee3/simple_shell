#include "shell.h"

/**
 * is_chain - current char in buffer tested if is a chain delimeter
 * @info:struct parameter
 * @buf: buffer char
 * @q: address of current position in buf
 *
 * Return: if chain delimeter 1, else 0
 */
int is_chain(info_t *info, char *buf, size_t *q)
{
	size_t k = *q;

	if (buf[k] == '|' && buf[k + 1] == '|')
	{
	buf[k] = 0;
	k++;
	info->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
	buf[k] = 0;
	k++;
	info->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';')
	{
	buf[k] = 0;
	info->cmd_buf_type = CMD_CHAIN;
	}
	else
	return (0);
	*q = k;
	return (1);
}


/**
 * check_chain - checks if chaining based on last status continue
 * @info: struct parameter
 * @buf: char buffer
 * @q: current position  in buf address
 * @i: buf starting position
 * @len: bud length
 *
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *q, size_t i, size_t len)
{
	size_t k = *q;

	if (info->cmd_buf_type == CMD_AND)
	{
	if (info->status)
	{
	buf[i] = 0;
	k = len;
	}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
	if (!info->status)
	{
	buf[i] = 0;
	k = len;
	}
	}
	*q = k;
}

/**
 * replace_alias - aliases replaced in the tokenized string
 * @info: struct parameter
 *
 * Return: if replaced 1, else 0
 */
int replace_alias(info_t *info)
{
	int num;
	list_t *node;
	char *q;

	for (num  = 0; num < 10; num++)
	{
	node = node_starts_with(info->alias, info->argv[0], '=');
	if (!node)
	return (0);
	free(info->argv[0]);
	q = _strchr(node->str, '=');
	if (!q)
	return (0);
	info->argv[0] = q;
	}
	return (1);
}

/**
 * replace_vars - vars in the tokenized string replaced
 * @info: struct parameter
 *
 * Return: if replaced 1, else 0
 */
int replace_vars(info_t *info)
{
	int num = 0;
	list_t *node;

	for (num = 0; info->argv[num]; num++)
	{
	if (info->argv[num][0] != '$' || !info->argv[num][1])
	continue;
	if (!strcmp(info->argv[num], "$?"))
	{
	replace_string(&(info->argv[num]),
		_strmap(convert_number(info->status, 10, 0)));
	continue;
	}
	if (!strcmp(info->argv[num], "$$"))
	{
	replace_string(&(info->argv[num]), _strmap(convert_number(getpid(), 10, 0)));
	continue;
	}
	node = node_starts_with(info->env, &info->argv[num][1], '=');
	if (node)
	{
	replace_string(&(info->argv[num]), _strmap(_strchr(node->str, '=' + 1)));
	continue;
	}
	replace_string(&info->argv[num], _strmap(""));
	}
	return (0);
}


/**
 * replace_string - replaces string
 * @old: old string address
 * @new: new string
 *
 * Return: is replaced 1, else 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

