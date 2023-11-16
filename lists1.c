#include "shell.h"

/**
 * lucky - determine the total length
 * @han: first node point
 *
 * Return: size of linked element
 */
size_t lucky(const list_t *han)
{
	size_t init = 0;

	while (han)
	{
		han = han->next;
		init++;
	}
	return (init);
}

/**
 * stringList - output an array of strings of point
 * @element: This is a pointer to first node
 *
 * Return: array only (string)
 */
char **stringList(list_t *element)
{
	list_t *layout = element;
	size_t ini = list_len(element), jan;
	char **stringer;
	char *string;

	if (!element || !ini)
		return (NULL);
	stringer = malloc(sizeof(char *) * (ini + 1));
	if (stringer == NULL)
		return (NULL);
	for (ini = 0; layout; layout = layout->next, ini++)
	{
		string = malloc(_strlen(layout->string) + 1);
		if (string == NULL)
		{
			for (jan = 0; jan < ini; jan++)
				free(stringer[jan]);
			free(stringer);
			return (NULL);
		}

		string = _strcpy(string, layout->string);
		stringer[ini] = string;
	}
	stringer[ini] = NULL;
	return (stringer);
}


/**
 * pointToList - print point to linkedlist
 * @han: pointer to first element
 *
 * Return: size only
 */
size_t pointToList(const list_t *han)
{
	size_t ini = 0;

	while (han)
	{
		_puts(convert_number(han->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(han->str ? han->str : "(nil)");
		_puts("\n");
		han = han->next;
		ini++;
	}
	return (ini);
}

/**
 * nodeStart - returns node with prefix
 * @layout: pointer to head
 * @prepare: string to compare
 * @chant: next character lateron prepare
 *
 * Return: match node or null
 */
list_t *nodeStart(list_t *layout, char *prepare, char chant)
{
	char *paper = NULL;

	while (layout)
	{
		paper = starts_with(layout->str, prepare);
		if (paper && ((chant == -1) || (*paper == chant)))
			return (layout);
		layout = layout->next;
	}
	return (NULL);
}

/**
 * nodeIndex - index of a node found
 * @element: head pointer
 * @layout: pointer to the node
 *
 * Return: either index or -1
 */
ssize_t nodeIndex(list_t *element, list_t *layout)
{
	size_t init = 0;

	while (element)
	{
		if (element == layout)
			return (init);
		element = element->next;
		init++;
	}
	return (-1);
}
