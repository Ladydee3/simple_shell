#include "shell.h"

/**
 * is_cmd - file determined if is an executable command
 * @info: struct info
 * @path: file path
 *
 * Return: if true 1, otherwise 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
	{
	return (1);
	}
	return (0);
}

/**
 * map_chars - character duplicated
 * @pathstr: string PATH
 * @start: index starting
 * @stop: index stopping
 *
 * Return: new buffer pointer
 */
char *map_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int num = 0, k = 0;

	for (k = 0, num = start; num < stop; num++)
	if (pathstr[num] != ':')
	buf[k++] = pathstr[num];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - cmd in the PATH string found
 * @info:struct info
 * @pathstr: string PATH
 * @cmd: cmd to find
 *
 * Return: if cmd founf full path  or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int num = 0, curr_pos = 0;
	char *path;

	if (pathstr)
	return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
	if (is_cmd(info, cmd))
	return (cmd);
	}
	while (1)
	{
	if (!pathstr[num] || pathstr[num] == ':')
	{
	path = map_chars(pathstr, curr_pos, num);
	if (!*path)
	_strcat(path, cmd);
	else
	{
	_strcat(path, "/");
	_strcat(path, cmd);
	}
	if (is_cmd(info, path))
	return (path);
	if (!pathstr[num])
	break;
	curr_pos = num;
	}
	num++;
	}
	return (NULL);
}
