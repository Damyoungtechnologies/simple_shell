#include "shell.h"

/**
 * part - this enables me to get historical file
 * @vine: another parameter in need
 *
 * Return: give me back my history file
 */

char *part(info_t *vine)
{
	char *bale, *rect;

	rect = _getenv(vine, "HOME=");
	if (rect == NULL)
		return (NULL);
	bale = malloc(sizeof(char) * (_strlen(rect) + _strlen(HIST_FILE) + 2));
	if (bale == NULL)
		return (NULL);
	bale[0] = 0;
	_strcpy(bale, rect);
	_strcat(bale, "/");
	_strcat(bale, HIST_FILE);
	return (bale);
}

/**
 * writer - creates or append a file
 * @vine: the parameter fine vine
 *
 * Return: 1 or -1
 */
int writer(info_t *vine)
{
	ssize_t fada;
	char *filer = part(vine);
	list_t *layout = NULL;

	if (filer == NULL)
		return (-1);

	fada = open(filer, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filer);
	if (fada == -1)
		return (-1);
	for (layout = vine->history; layout; layout = layout->next)
	{
		_putsfd(layout->str, fada);
		_putfd('\n', fada);
	}
	_putfd(BUF_FLUSH, fada);
	close(fada);
	return (1);
}

/**
 * reader - reads only file history
 * @vine: the parameter to be delayed
 *
 * Return: count history when successful
 */
int reader(info_t *vine)
{
	int ini, mark = 0, counter = 0;
	ssize_t fada, lettuce, fsize = 0;
	struct stat steady;
	char *bale = NULL, *filer = part(vine);

	if (filer == NULL)
		return (0);

	fada = open(filer, O_RDONLY);
	free(filer);
	if (fada == -1)
		return (0);
	if (!fstat(fada, &steady))
		fsize = steady.st_size;
	if (fsize < 2)
		return (0);
	bale = malloc(sizeof(char) * (fsize + 1));
	if (bale == NULL)
		return (0);
	lettuce = read(fada, bale, fsize);
	bale[fsize] = 0;
	if (lettuce <= 0)
		return (free(bale), 0);
	close(fada);
	for (ini = 0; ini < fsize; ini++)
		if (bale[ini] == '\n')
		{
			bale[ini] = 0;
			builder(vine, bale + mark, counter++);
			mark = ini + 1;
		}
	if (mark != ini)
		builder(vine, bale + mark, counter++);
	free(bale);
	vine->histcount = counter;
	while (vine->histcount-- >= HIST_MAX)
		delete_node_at_index(&(vine->history), 0);
	number(vine);
	return (vine->histcount);
}

/**
 * builder - sum entry to history list
 * @vine: Struct containing required arguments.
 * @bale: my buffer
 * @counter: the history linecount, histcount
 *
 * Return: 0 if successful
 */
int builder(info_t *vine, char *bale, int counter)
{
	list_t *layout = NULL;

	if (vine->history)
		vine = vine->history;
	add_node_end(&layout, bale, counter);

	if (!vine->history)
		vine->history = layout;
	return (0);
}

/**
 * number - history linkedlist renumbered
 * @vine: potential argument structure
 *
 * Return: new history count
 */
int number(info_t *vine)
{
	list_t *layout = vine->history;
	int ini = 0;

	while (layout)
	{
		layout->num = ini++;
		layout = layout->next;
	}
	return (vine->histcount = ini);
}
