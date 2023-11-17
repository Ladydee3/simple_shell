
#include "shell.h"

/**
 * interactive - if shell is in interactive mode shell is true
 * @info: address struct
 *
 * Return: 0 otherwise, 1 if interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - delimeter character checked
 * @delim:string delimeter
 * @c: check char
 * Return: `1 on true and 0 on false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	if (*delim++ == c)
	return (1);
	return (0);
}

/**
 * _isalpha - alphabetic character checked
 * @c: character input
 * Return: if c is alphabetic 1, otherwise 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	return (1);
	else
	return (0);
}

/**
 * _atoi - integer string converted
 * @s: string to be converted
 * Return: if no numbers in string 1, or else 0
 */
int _atoi(char *s)
{
	int num, sign = 0, flag = 0, output;
	unsigned int result = 0;

	for (num = 0; s[num] != '\0' && flag != 2; num++)
	{
	if (s[num] == '-')
	sign *= -1;

	if (s[num] >= '0' && s[num] <= '9')
	{
	flag = 1;
	result *= 10;
	result += (s[num] - '0');
	}
	else if (flag == 1)
	flag = 2;
	}

	if (sign == -1)
	output = -result;
	else
	output = result;

	return (output);
}
