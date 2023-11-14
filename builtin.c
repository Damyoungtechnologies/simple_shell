#include "shell.h"

/**
 * exeat - come out of the shell
 * @life: content of potential lang
 *  Return: exits with a given escape
 *         (0) if info.argv[0] != "exit"
 */
int exeat(info_t *life)
{
	int exiting;

	if (life->argv[1])  /* If there is an exit arguement */
	{
		exiting = _erratoi(life->argv[1]);
		if (exiting == -1)
		{
			life->status = 2;
			print_error(life, "Illegal number: ");
			_eputs(life->argv[1]);
			_eputchar('\n');
			return (1);
		}
		life->err_num = _erratoi(life->argv[1]);
		return (-2);
	}
	life->err_num = -1;
	return (-2);
}

/**
 * compact - changes the current directory disk
 * @fine: Strucl potential arguments only
 *          constant function prototype ainit
 *  Return: Always 0 on success
 */
int compact(info_t *fine)
{
	char *sir, *dir, buffer[1024];
	int chdir_ret;

	sir = getcwd(buffer, 1024);
if (!sir)
_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!fine->argv[1])
	{
		dir = _getenv(fine, "HOME=");
if (!dir)
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(fine, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(fine->argv[1], "-") == 0)
	{
		if (!_getenv(fine, "OLDPWD="))
		{
			_puts(sir);
			_putchar('\n');
			return (1);
		}
_puts(_getenv(fine, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(fine, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(fine->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(fine, "can't cd to ");
	_eputs(fine->argv[1]), _eputchar('\n');
	}
	else
	{
_setenv(fine, "OLDPWD", _getenv(fine, "PWD="));
	_setenv(fine, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * assist - changes the current directory to help
 * @amp: Structure containing potential arguments kor
 *          constant function prototype again
 *  Return: Always 0 when successful
 */
int assist(info_t *amp)
{
	char **argar;

	argar = amp->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argar); /* temp att_unused workaround */
	return (0);
}
