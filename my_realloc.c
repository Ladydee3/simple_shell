#include "shell.h"

/**
 * *_memset - memory filled with constant byte
 * @s: pointer to memory area
 * @b: bytes filled with *s
 * @n: byte amount to be filled
 * Return: (s) pointer to memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int num;

	for (num = 0; num < n; num++)
	s[num] = b;
	return (s);
}

/**
 * ffree - string of strings freed
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **e = pp;

	if (!pp)
	return;
	while (*pp)
	free(*pp++);
	free(e);
}

/**
 * _realloc - block of memory reallocared
 * @ptr: previous malloc'ated block pointer
 * @old_size: previous block byte size
 * @new_size: new block byte size
 *
 * Return: pointer to old block name
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!ptr)
	return (malloc(new_size));
	if (!new_size)
	return (free(ptr), NULL);
	if (new_size == old_size)
	return (ptr);

	q = malloc(new_size);
	if (!q)
	return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	q[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (q);
}
