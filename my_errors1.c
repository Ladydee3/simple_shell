#include "shell.h"

/**
 * print_d - decimal function printed (integer) number (base 10)
 * @fd: file description to write to
 * @input: input
 *
 * Return: amount of character printed
 */
int print_d(int input, int fd)
{
	int (*_putchar)(char) = _putchar;
	int num, count = 0;
	unsigned int _sab_, current;

	if (fd == STDERR_FILENO)
	_putchar =  _eputchar;
	if (input < 0)
	{

	_sab_ = -input;
	_putchar('-');
	count++;
	}
	else
	_sab_ = input;
	current = _sab_;
	for (num = 1000000000; num > 1;  num /= 10)
	{
	if (_sab_ / num)
	{
	_putchar('0' + current / num);
	count++;
	}
	current %= num;
	}
	_putchar('0' + current);
	count++;

	return (count);
}

/**
 * _erratoi - string converted to  integer
 * @s: string to be converted
 * Return: if no numbers in string 0, otherwise convrted
 *           number -1 on error
 */
int _erratoi(char *s)
{
	int num = 0;

	unsigned long int result = 0;

	if (*s == '+')
	s++;
	for (num = 0; s[num] != '\0'; num++)
	{
	if (s[num] >= '0' && s[num] <= '9')
	{
	result *= 10;
	result += (s[num] - '0');
	if (result > INT_MAX)
	return (-1);
	}
	else
	return (-1);
	}
	return (result);
}

/**
 * remove_comments - first instance of '#' function
 *        replaces with '\0'
 * @buf: string sddress to modify
 *
 * Return: 0 always
 */
void remove_comments(char *buf)
{
	int num;

	for (num = 0; buf[num] != '\0'; num++)
	if (buf[num] == '#' && (!num || buf[num - 1] == ' '))
	{
	buf[num] = '\0';
	break;
	}
}

/**
 * print_error - error message printed
 * @estr: specified error type contained in string
 * @info: return info struct and parameter
 * Return: if no number in string 0, -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs("; ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * convert_number - function converted, a clone of itoa
 * @base: base
 * @flags: flags arguments
 * @num: number
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long a = num;


	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
	a = num;
	sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
	*--ptr = array[a & base];
	a /=  base;

	} while (a != 0);

	if (sign)
	*--ptr = sign;
	return (ptr);
}

