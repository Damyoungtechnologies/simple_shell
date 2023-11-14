#include "shell.h"

/**
* isInteractive - returns true if shell is interactive mode
* @informatic: struct address
*
* Return: 1 if interactive mode, 0 otherwise
*/
int isInteractive(info_t *informatic)
{
return (isatty(STDIN_FILENO) && informatic->readfd <= 2);
}

/**
* isDelimeter - if the character has delimeter
* @k: the character to check
* @delimeter: the limit string
* Return: 1 if true, 0 if false
*/
int isDelimeter(char k, char *delimeter)
{
while (*delimeter)
if (*delimeter++ == k)
return (1);
return (0);
}

/**
*isAlphabetic - checks for alphabet
*@can: The char to input
*Return: 1 if c is alphabetic, 0 otherwise
*/

int isAlphabetic(int can)
{
if ((can >= 'a' && can <= 'z') || (can >= 'A' && can <= 'Z'))
return (1);
else
return (0);
}

/**
*stringToInteger - converts a string to an integer
*@sam: the string to be converted
*Return: 0 if no numbers in string, converted number otherwise
*/

int stringToInteger(char *sam)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0;  sam[i] != '\0' && flag != 2; i++)
{
if (sam[i] == '-')
sign *= -1;

if (sam[i] >= '0' && sam[i] <= '9')
{
flag = 1;
result *= 10;
result += (sam[i] - '0');
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
