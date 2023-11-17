#include "shell.h"

/**
 * _mycd - current directory of the process changed
 * @info: structure  containimg potetial arguments, used to
 *        maintan function prototype
 *
 * Return: 0 always
 */
int _mycd(info_t *info)
{
	char *c, *dir, buffer[1024];
	int chdir_ret;

	c = getcwd(buffer, 1024);
	if (!c)
	_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
	dir = _getenv(info, "HOME=");
	if (!dir)
	chdir_ret = /* TODO: what should this be? */ 
	chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
	else
	chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
	if (!_getenv(info, "OLDPWD="))
	{
	_puts(c);
	_putchar('\n');
	return (1);
	}
	_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
	chdir_ret = /* TODO: what should this be? */
	chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	chdir_ret = chdir(info->argv[1]);
	if ( chdir_ret == -1)
	{
	print_error(info, "can't cd to ");
	_eputs(info->argv[1]), _putchar('\n');
	}
	else
	{
	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - current directory of the process changed
 * @info: structure containg potetial argument, used to
 *         maitain costant fuction prototype
 * Return: 0 always
 */
int _myhelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("Help call works. Function not yet implemented\n");
if (0)
_puts(*arg_array);
return (0);
}

/**
 * _myexit - shell exit
 * @info: structre containing potetial arguments, used to
 *        maintain function prototype
 * Return: 0 if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
int exitcheck;

if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_putchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

