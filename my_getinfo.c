#include "shell.h"

/**
 * set_info - info_t struct initialized
 * @av: vector argument
 * @info: address stuct
 */
void set_info(info_t *info, char **av)
{
	int num = 0;

	info->fname = av[0];
	if (info->argv)
	{
	info->argv  = strtow(info->arg, "\t");
	if (!info->argv)
	{

	info->arg = malloc(sizeof(char *) * 2);
	if (info->argv)
	{
	info->argv[0] = _strmap(info->arg);
	info->argv[1] = NULL;
	}
	}
	for (num = 0 ; info->argv && info->argv[num]; num++)
		;
	info->argc = num;

	replace_alias(info);
	replace_vars(info);
	}
}

/**
 * clear_info - info struct initialixed
 * @info: address struct
 */
void clear_info(info_t *info)
{
	info->argv = NULL;
	info->arg = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * free_info - info struct fields freed
 * @all: all field are freed if true
 * @info: address struct
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
	if (!info->cmd_buf)
	free(info->arg);
	if (info->env)
	free_list(&(info->env));
	if (info->history)
	free_list(&(info->history));
	if (info->alias)
	ffree(info->environ);
	info->environ = NULL;
	bfree((void **)info->cmd_buf);
	if (info->readfd > 2)
	close(info->readfd);
	_putchar(BUF_FLUSH);
	}
}
