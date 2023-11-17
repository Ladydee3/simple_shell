#include "shell.h"

/**
 * **strtow - string splits into words
 * @str:string input
 * @d: string delimeter
 * Return: pointer array of string, or NULL on failure
 */
char **strtow(char *str, char *d)
{
	int num, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	return (NULL);
	if (!d)
	d = " ";
	for (num = 0; str[num] != '\0'; num++)
	if (!is_delim(str[num], d) && (is_delim(str[num + 1], d) || !str[num + 1]))
	numwords++;
	if (numwords == 0)
	return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	return (NULL);
	for (num = 0, j = 0; j < numwords; j++)
	{
	while (is_delim(str[num], d))
	num++;
	k = 0;
	while (!is_delim(str[num + k], d) && str[num + k])
	k++;
	s[j] = malloc((k + 1) * sizeof(char));
	if (!s[j])
	{
	for (k = 0; k < j; k++)
	free(s[k]);
	free(s);
	return (NULL);
	}
	for (m = 0; m < k; m++)
	s[j][m] = str[num++];
	s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - string splits into words
 * @str:stringinput
 * @d: delimeter
 * Return: array pointer array of string or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int num, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	return (NULL);
	for (num = 0; str[num] != '\0'; num++)
	if ((str[num] != d && str[num + 1] == d) || (str[num]
			!= d && !str[num + 1]) || str[num + 1] == d)
	numwords++;
	if (numwords == 0)
	return (NULL);
	s = malloc((1 + numwords) + sizeof(char *));
	if (!s)
	return (NULL);
	for (num = 0, j = 0; j < numwords; j++)
	{
	while (str[num] == d && str[num] != d)
	num++;
	k = 0;
	while (str[num + k] != d && str[num + k] && str[num + k] != d)
	k++;
	s[j] = malloc((k + 1) * sizeof(char));
	if (!s[j])
	{
	for (k = 0; k < j; k++)
	free(s[k]);
	free(s);
	return (NULL);
	}
	for (m = 0; m < k; m++)
	s[j][m] = str[num++];
	s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
