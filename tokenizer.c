#include "shell.h"

/**
* **stringtow - splits a string into words. Repeat delimiters are ignored
* @str: the input string
* @dl: the delim string
* Return: a pointer to an array of strings, or NULL on failure
*/

char **stringtow(char *str, char *dl)
{
int i, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!dl)
dl = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], dl) && (is_delim(str[i + 1], dl) || !str[i + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(str[i], dl))
i++;
k = 0;
while (!is_delim(str[i + k], dl) && str[i + k])
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
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
* **stringtow2 - splits a string into words
* @string: the input string
* @dl: the delim
* Return: a pointer to an array of strings, or NULL on failure
*/
char **stringtow2(char *string, char dl)
{
int i, j, k, m, numwords = 0;
char **s;

if (string == NULL || string[0] == 0)
return (NULL);
for (i = 0; string[i] != '\0'; i++)
if ((string[i] != dl && string[i + 1] == dl) ||
(string[i] != dl && !string[i + 1]) || string[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (string[i] == dl && string[i] != dl)
i++;
k = 0;
while (string[i + k] != dl && string[i + k] && string[i + k] != dl)
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
s[j][m] = string[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}
