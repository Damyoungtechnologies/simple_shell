#include "shell.h"

/**
* stringlen - returns the length of a string
* @ss: the string whose length to check
*
* Return: integer length of string
*/
int stringlen(char *ss)
{
int i = 0;

if (!ss)
return (0);

while (*ss++)
i++;
return (i);
}

/**
* stringcmp - performs lexicogarphic comparison of two strangs.
* @ss1: the first strang
* @ss2: the second strang
*
* Return: negative if ss1 < ss2, positive if ss1 > ss2, zero if ss1 == ss2
*/
int stringcmp(char *ss1, char *ss2)
{
while (*ss1 && *ss2)
{
if (*ss1 != *ss2)
return (*ss1 - *ss2);
ss1++;
ss2++;
}
if (*ss1 == *ss2)
return (0);
else
return (*ss1 < *ss2 ? -1 : 1);
}

/**
* starts_with - checks if needle starts with haystack
* @haystack: string to search
* @needle: the substring to find
*
* Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* stringcat - concatenates two strings
* @dest: the destination buffer
* @source: the source buffer
*
* Return: pointer to destination buffer
*/
char *stringcat(char *dest, char *source)
{
char *ret = dest;

while (*dest)
dest++;
while (*source)
*dest++ = *source++;
*dest = *source;
return (ret);
}
