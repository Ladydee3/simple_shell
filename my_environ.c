#include "shell.h"

/**
 * _myenv - current environment printed
 * @info: structutr containing potetial arguments
 * Return: 0 always
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets  value of environ viriable
 * @info: structure containing potetial arguments
 * @name: var env name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
	q = starts_with(node->str, name);
	if (q && *q)
	return (q);
	node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - new environment viriable initialized or modify
 *              an existing one
 * @info: structure containing potential arguments
 *
 * Return: 0 always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
	_puts("incorrect number of arguments\n");
	return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	return (0);
	return (1);
}

/**
 * _myunsetenv - environment viriable removed
 * @info: structute containing potential argument
 *
 * Return: 0 always:
 */
int _myunsetenv(info_t *info)
{
	int num;

	if (info->argc == 1)
	{
	_eputs("Too few arguments.\n");
	return (1);
	}
	for (num = 1; num <= info->argc; num++)
	_unsetenv(info, info->argv[num]);
	return (0);
}

/**
 * populate_env_list - env linked list populated
 * @info: structure containing potential arguments
 * Return: 0 always
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t num;

	for (num = 0; environ[num]; num++)
	add_node_end(&node, environ[num], 0);
	info->env = node;
	return (0);
}
