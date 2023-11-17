#include "shell.h"

/**
 * _putsfd - input string printed
 * @fd: file description to write to
 * @str: string to be printed
 *
 * Return: chars put number
 */
int _putsfd(char *str, int fd)
{
	int num = 0;

	if (!str)
	return (0);
	while (*str)
	{
	num += _putfd(*str++, fd);
	}
	return (num);
}

/**
 * _putfd - chaaracter c to given fd written
 * @fd: filr descriptor to write to
 * @c: print character to print
 *
 * Return: 1 on success, -1 on error is returned
 */
int _putfd(char c, int fd)
{
	static int num;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || num >= WRITE_BUF_SIZE)
	{
	write(fd, buf, num);
	num = 0;
	}
	if (c != BUF_FLUSH)
	buf[num++] = c;
	return (1);
}

/**
 * _eputchar - charavter to c stderr printed
 * @c: character to print
 *
 * Return: 1 on success, -1 on error is returned
 */
int _eputchar(char c)
{
	static int num;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || num >= WRITE_BUF_SIZE)
	{
	write(2, buf, num);
	num = 0;
	}
	if (c != BUF_FLUSH)
	buf[num++] = c;
	return (1);
}

/**
 * _eputs - input string printed
 * @str: string to be printed
 *
 * Return: Nill
 */
void _eputs(char *str)
{
	int num = 0;

	if (!str)
	return;
	while (str[num] != '\0')
	{
	_eputchar(str[num]);
	num++;
	}
}
