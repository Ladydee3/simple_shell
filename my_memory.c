#include <stdlib.h>
#include "shell.h"

/**
* bfree - frees pointer and NULL the address
* @ptr: address of pinter to be free
*
* Return: if freed 1 otherwise 0
*/
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
