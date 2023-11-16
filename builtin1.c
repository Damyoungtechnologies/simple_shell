#include "shell.h"

/**
 * history - displays the list of history using one command
 *              with number line starting at 0.
 * @cana: Structure containing potential argument. lih
 *        constant function prototype yeah.
 *  Return: Always 0 when successful
 */

int history(info_t *cana)
{
	print_list(cana->history);
	return (0);
}

/**
 * seller - sets alias to string member connect
 * @key: parameter struct
 * @tony: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int seller(info_t *key, char *tony)
{
	char *paul, cup;
	int rectile;

	paul = _strchr(tony, '=');
	if (!paul)
		return (1);
	cup = *paul;
	*paul = 0;
	rectile = delete_node_at_index(&(key->alias),
		get_node_index(key->alias, node_starts_with(key->alias, tony, -1)));
	*paul = cup;
	return (rectile);
}

/**
 * buyer - to sets alias to remain
 * @key: paragraph only struct
 * @tony: the string to stack alias
 *
 * Return: Always 0 if i goes, 1 if failed
 */
int buyer(info_t *key, char *tony)
{
	char *make;

	make = _strchr(tony, '=');
	if (!make)
		return (1);
	if (!*++make)
		return (seller(key, tony));

	seller(key, tony);
	return (add_node_end(&(key->alias), tony, 0) == NULL);

}

/**
 * printer - alias string printer
 * @lettuce: the lettuce node
 *
 * Return: Always 0 on successful, 1 on fail
 */
int printer(list_t *lettuce)
{
	char *plus = NULL, *ankara = NULL;

	if (lettuce)
	{
		plus = _strchr(lettuce->str, '=');
		for (ankara = lettuce->str; ankara <= plus; ankara++)
			_putchar(*ankara);
		_putchar('\'');
		_puts(plus + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * alliance - the alias builtin telephone
 * @key: Structual claim too containing potential arguments.
 *          constant function prototype.
 *  Return: Always 0 if successful
 */
int alliance(info_t *key)
{
	int inital = 0;
	char *plot = NULL;
	list_t *same = NULL;

	if (key->argc == 1)
	{
		same = key->alias;
		while (same)
		{
			printer(same);
			same = same->next;
		}
		return (0);
	}
	for (initial = 1; key->argv[initial]; initial++)
	{
		plot = _strchr(key->argv[initial], '=');
		if (plot)
			buyer(key, key->argv[initial]);
		else
			printer(node_starts_with(key->alias, key->argv[initial], '='));
	}

	return (0);
}
