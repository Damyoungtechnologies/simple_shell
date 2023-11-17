#include "shell.h"

/**
* myenviron - prints the current environment
* @infos: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/
int myenviron(info_t *infos)
{
print_list_str(infos->env);
return (0);
}

/**
* _getenviron - gets the value of an environ variable
* @infor: Structure containing potential arguments. Used to maintain
* @name: environ var name
*
* Return: the value
*/
char *_getenviron(info_t *infor, const char *name)
{
list_t *node = infor->env;
char *p;

while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
* mysetenviron - Initialize a new environment variable,
*             or modify an existing one
* @i: Structure containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/
int mysetenviron(info_t *i)
{
if (i->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(i, i->argv[1], i->argv[2]))
return (0);
return (1);
}

/**
* myunsetenv - Remove an environment variable
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always 0
*/
int myunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);

return (0);
}

/**
* pop_environ_list - populates environ linked list
* @intro: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/
int pop_environ_list(info_t *intro)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
intro->env = node;
return (0);
}
