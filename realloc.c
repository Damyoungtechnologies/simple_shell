#include "shell.h"

/**
**Memoryset - fills memory with a constant byte
*@s: the pointer to the memory area
*@bit: the byte to fill *s with
*@num: the amount of bytes to be filled
*Return: (s) a pointer to the memory area s
*/
char *Memoryset(char *s, char bit, unsigned int num)
{
unsigned int i;

for (i = 0; i < num; i++)
s[i] = bit;
return (s);
}

/**
* forfree - frees a string of strings
* @dd: string of strings
*/
void forfree(char **dd)
{
char **a = dd;

if (!dd)
return;
while (*dd)
free(*dd++);
free(a);
}

/**
* reallocation - reallocates a block of memory
* @ptr: pointer to previous malloc'ated block
* @old_size: byte size of previous block
* @new_size: byte size of new block
*
* Return: pointer to the old block name
*/
void *reallocation(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
