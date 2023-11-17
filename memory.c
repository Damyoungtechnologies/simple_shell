#include "shell.h"

/**
* befree - frees a pointer and makes the address empty
* @pptr: address of the pointer to free
*
* Return: 1 if freed, otherwise 0.
*/
int befree(void **pptr)
{
if (pptr && *pptr)
{
free(*pptr);
*pptr = NULL;
return (1);
}
return (0);
}
