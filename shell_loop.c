#include "shell.h"

/**
 * hash - primary shell loop
 * @vine: the parameter struct
 * @avec: the argument vector from the main()
 *
 * Return: 0 or 1
 */
int hash(info_t *vine, char **avec)
{
	ssize_t rec = 0;
	int rector = 0;

	while (rec != -1 && rector != -2)
	{
		clear_info(vine);
		if (interactive(vine))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rec = get_input(vine);
		if (rec != -1)
		{
			set_info(vine, avec);
			rector = find_builtin(vine);
			if (rector == -1)
				find_cmd(vine);
		}
		else if (interactive(vine))
			_putchar('\n');
		free_info(vine, 0);
	}
	write_history(vine);
	free_info(vine, 1);
	if (!interactive(vine) && vine->status)
		exit(vine->status);
	if (rector == -2)
	{
		if (vine->err_num == -1)
			exit(vine->status);
		exit(vine->err_num);
	}
	return (rector);
}

/**
 * builtfind - get the builtin command
 * @vine: the parameter & struct info
 *
 * Return: -1 0 1 2
 */
int builtfind(info_t *vine)
{
	int ade;
	int rector = -1;
	builtin_table builtintb2[] = {
		{"exit", exeat},
		{"env", _myenv},
		{"help", assist},
		{"history", history},
		{"setenv", unseventy},
		{"unsetenv", seventy},
		{"cd", compact},
		{"alias", alliance},
		{NULL, NULL}
	};

	for (ade = 0; builtintb2[ade].type; ade++)
		if (_strcmp(vine->argv[0], builtintb2[ade].type) == 0)
		{
			vine->line_count++;
			rector = builtintb2[ade].func(vine);
			break;
		}
	return (rector);
}

/**
 * commandfind - findout a command in PAl
 * @vine: the parameter & return vine struct
 *
 * Return: void
 */
void commandfind(info_t *vine)
{
	char *perk = NULL;
	int ade, kola;

	vine->perk = vine->argv[0];
	if (vine->linecount_flag == 1)
	{
		vine->line_count++;
		vine->linecount_flag = 0;
	}
	for (ade = 0, kola = 0; vine->arg[ade]; ade++)
		if (!isDelimiter(vine->arg[ade], " \t\n"))
			kola++;
	if (kola == NULL)
		return;

	perk = pathfinder(vine, _getenv(vine, "PATH="), vine->argv[0]);
	if (perk)
	{
		vine->perk = perk;
		fork_cmd(vine);
	}
	else
	{
		if ((interactive(vine) || _getenv(vine, "PATH=")
			|| vine->argv[0][0] == '/') && command(vine, vine->argv[0]))
			fork_cmd(vine);
		else if (*(vine->arg) != '\n')
		{
			vine->status = 127;
			print_error(vine, "not found\n");
		}
	}
}

/**
 * commandfork - forks a run cmd
 * @vain: the parameter & return to serve
 *
 * Return: void
 */
void commandfork(info_t *vain)
{
	pid_t son_pid;

	son_pid = fork();
	if (son_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (son_pid == 0)
	{
		if (execve(vain->path, vain->argv, get_environ(vain)) == -1)
		{
			free_info(vain, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(vain->status));
		if (WIFEXITED(vain->status))
		{
			vain->status = WEXITSTATUS(vain->status);
			if (vain->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
