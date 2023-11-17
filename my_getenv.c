#include "shell.h"

/**
 * _setenv - new environment viriable initialized, or
 *          an existing one modify
 * @var: env var property string
 * @info: structute containing potetial argument, used
 *        to maintain function ptototype
 * @value: env var value string
 * Return: 0 always
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *q;

	if (!var || !value)
	return (0);

	buf = malloc(strlen(var) + _strlen(value) + 2);
	if (!buf)
	return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
	q = starts_with(node->str, var);
	if (q && *q == '=')
	{
	free(node->str);
	node->str = buf;
	info->env_changed = 1;
	return (0);
	}
	node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

/**
 * _unsetenv - rnviromnent viriable removed
 * @var: env var property string
 * @info: structure containing potetial argument, used to
 *        maaintain function prototpe
 * Return: on delete 1, otherwise 0
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t num = 0;
	char *q;

	if (!node || !var)
	return (0);

	while (node)
	{
	q = starts_with(node->str, var);
	if (q && *q == '=')
	{
	info->env_changed = delete_node_at_index(&(info->env), num);
	num = 0;
	node = info->env;
	continue;
	}
	node = node->next;
	num++;
	}
	return (info->env_changed);
}

/**
 * get_environ - copy of our environ string array returned
 * @info: structure containing potetial argument, used to
 *         maintain function prototype
 * Return: 0 always
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
	info->environ = list_to_strings(info->env);
	info->env_changed = 0;
	}
	return (info->environ);
}

