#include "shell.h"

/**
* main - entry point
* @acc: arg count
* @avec: arg vector
*
* Return: 0 on success, 1 on unsuccessful
*/
int main(int acc, char **avec)
{
info_t info[] = { INFO_INIT };
int ffd = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (ffd)
: "r" (ffd));

if (acc == 2)
{
ffd = open(avec[1], O_RDONLY);
if (ffd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(avec[0]);
_eputs(": 0: Can't open ");
_eputs(avec[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readffd = ffd;
}
populate_env_list(info);
read_history(info);
hsh(info, avec);
return (EXIT_SUCCESS);
}
