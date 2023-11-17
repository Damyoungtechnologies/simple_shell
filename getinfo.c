#include "shell.h"

/**
* clear_info - initializes info_t struct
* @info: struct address
*/
void clear_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}

/**
* set_in - initializes info_t struct
* @info: struct address
* @arvec: argument vector
*/
void set_in(info_t *info, char **arvec)
{
int i = 0;

info->fname = arvec[0];
if (info->arg)
{
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{

info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;

replace_alias(info);
replace_vars(info);
}
}

/**
* free_i - frees info_t struct fields
* @in: struct address
* @all: true if freeing all fields
*/
void free_i(in_t *in, int all)
{
ffree(in->argv);
in->argv = NULL;
in->path = NULL;
if (all)
{
if (!in->cmd_buf)
free(in->arg);
if (in->env)
free_list(&(in->env));
if (in->history)
free_list(&(in->history));
if (in->alias)
free_list(&(in->alias));
ffree(in->environ);
in->environ = NULL;
bfree((void **)in->cmd_buf);
if (in->readfd > 2)
close(in->readfd);
_putchar(BUF_FLUSH);
}
}
