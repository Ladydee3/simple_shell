#include "shell.h"

/**
 * _strlen - length of string returned
 * @s: string length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int num = 0;

	if (!s)
	return (0);

	while (*s++)
	num++;
	return (num);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strang
 * @s1: first strand
 * @s2: second strand
 *
 * Return: if s1 > s2 positive
 *            s1 < s2 negative
 *            s1 == s2 zero
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
	if (*s1 != *s2)
	return (*s1 - *s2);
	s1++;
	s2++;
	}
	if (*s1 == *s2)
	return (0);
	else
	return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - check if needle start with haystack
 * @haystack: search string
 * @needle: substring to find
 *
 * Return: next address of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	if (*needle++ != *haystack++)
	return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - two string concatenated
 * @dest: buffer dstination
 * @src: buffer source
 *
 * Return: bufer destination buffer pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	dest++;
	while (*src)
	*dest++ = *src++;
	*dest = *src;
	return (ret);
}

