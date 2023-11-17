#include "shell.h"

/**
 * *_strncpy - string copied
 * @dest: string destination coped to
 * @src: source string
 * @n: character amount to be copied
 * Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int num, k;
	char *c = dest;

	num = 0;
	while (src[num] != '\0' && num < n - 1)
	{
	dest[num] = src[num];
	num++;
	}
	if (num < n)
	{
	k = num;
	while (k < n)
	{
	dest[k] = '\0';
	k++;
	}
	}
	return (c);
}

/**
 * *_strncat - two string concatenated
 * @dest: first string
 * @src: second string
 * @n: amount of bytes to be maximally used
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int num, k;
	char *c = dest;

	num = 0;
	k = 0;
	while (dest[num] != '\0')
	num++;
	while (src[k] != '\0' && k < n)
	{
	dest[num] = src[k];
	num++;
	k++;
	}
	if (k < n)
	dest[num] = '\0';
	return (c);
}

/**
 * _strchr - character located in string
 * @s: string to be parsed
 * @c: character to look
 * Return: (s) pointer to  memory area s
 */
char *_strchr(char *s, char c)
{
	do {
	if (*s == c)
	return (s);
	} while (*s++ != '\0');
	return (NULL);
}
