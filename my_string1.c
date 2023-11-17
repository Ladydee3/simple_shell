#include "shell.h"

/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 *
 * Return: destination pointer
 */
char *_strcpy(char *dest, char *src)
{
	int num = 0;

	if (dest == src || src == 0)
	return (dest);
	while (src[num])
	{
	dest[num] = src[num];
	num++;
	}
	dest[num] = 0;
	return (dest);
}

/**
 * _strmap - duplicate string
 * @str: the string to duplicate
 *
 * Return: duplicate sstring pointer
 */
char *_strmap(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	return (NULL);
	while (*str++)
	length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	return (NULL);
	for (length++; length--;)
	ret[length] = *--str;
	return (ret);
}

/**
 * _puts - prints input string
 * @str:string to be printed
 *
 * Return: Nil
 */
void _puts(char *str)
{
	int num = 0;

	if (!str)
	return;
	while (str[num] != '\0')
	{
	_putchar(str[num]);
	num++;
	}
}

/**
 * _putchar - character c written to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error, is returned errno is set
 */
int _putchar(char c)
{
	static int num;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || num >= WRITE_BUF_SIZE)
	{
	write(1, buf, num);
	num = 0;
	}
	if (c != BUF_FLUSH)
	buf[num++] = c;
	return (1);
}
