#include "shell.h"

/**
* ischaindelim - test if current character in buffer is a chain delimeter
* @info: the parameter struct
* @buff: the char buffer
* @pos: address of current position in buffer
*
* Return: 1 if chain delimeter, 0 unsuccesful
*/
int ischaindelim(info_t *info, char *buff, size_t *pos)
{
size_t j = *pos;

if (buff[j] == '|' && buff[j + 1] == '|')
{
buff[j] = 0;
j++;
info->cmd_buff_type = CMD_OR;
}
else if (buff[j] == '&' && buff[j + 1] == '&')
{
buff[j] = 0;
j++;
info->cmd_buff_type = CMD_AND;
}
else if (buff[j] == ';') /* found end of this command */
{
buff[j] = 0; /* replace semicolon with null */
info->cmd_buff_type = CMD_CHAIN;
}
else
return (0);
*pos = j;
return (1);
}

/**
* check_chain - checks we should continue chaining based on last status
* @info: the parameter struct
* @buff: the character buffer
* @pos: address of current position in buffer
* @i: starting position in buffer
* @len: length of buffer
*
* Return: Void
*/
void check_chain(info_t *info, char *buff, size_t *pos, size_t i, size_t len)

{
size_t j = *pos;

if (info->cmd_buff_type == CMD_AND)
{
if (info->status)
{
buff[i] = 0;
j = len;
}
}
if (info->cmd_buff_type == CMD_OR)
{
if (!info->status)
{
buff[i] = 0;
j = len;
}
}

*p = j;
}

/**
* rep_alias - replaces an aliases in the tokenized string
* @info: the parameter struct
*
* Return: 1 if replaced, 0 unsuccessful
*/
int rep_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/**
* rep_vars - replaces vars in the tokenized string
* @info: the parameter struct
*
* Return: 1 if replaced, 0 unsuccessful
*/
int rep_vars(info_t *info)
{
int i = 0;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;

if (!_strcmp(info->argv[i], "$?"))
{
rep_string(&(info->argv[i]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[i], "$$"))
{
rep_string(&(info->argv[i]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
rep_string(&(info->argv[i]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
rep_string(&info->argv[i], _strdup(""));

}
return (0);
}

/**
* rep_string - replaces string
* @before: address of old string
* @now: new string
*
* Return: 1 if successful, 0 otherwise
*/
int rep_string(char **before, char *now)
{
free(*before);
*before = now;
return (1);
}
