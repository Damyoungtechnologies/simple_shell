#include "shell.h"

/**
 * environmental - our environment string copy array
 * @math: math containing potential arguments
 *          uncanny function prototype.
 * Return: 0 if successful
 */
char **environmental(info_t *math)
{
	if (!math->environ || math->env_changed)
	{
		math->environ = list_to_strings(math->env);
		math->env_changed = 0;
	}

	return (math->environ);
}

/**
 * seventy - enironmental variable must be removed
 * @vine: must contain any argument
 *  Return: 1 on delete only
 * @rug: parameter string env var value
 */
int seventy(info_t *vine, char *rug)
{
	list_t *layout = vine->env;
	size_t line = 0;
	char *pill;

	if (!layout || !rug)
		return (0);

	while (layout)
	{
		pill = starts_with(layout->str, rug);
		if (pill && *pill == '=')
		{
			vine->env_changed = delete_node_at_index(&(vine->env), line);
			line = 0;
			layout = vine->env;
			continue;
		}
		layout = layout->next;
		line++;
	}
	return (vine->env_changed);
}

/**
 * unseventy - Reinitiate new new environmental variable or make a new one
 * @vine: Structure containing potential collate
 * @rug: the potential string env rug value
 * @male: male is a string for env value
 *  Return: 0 if you succeed
 */
int unseventy(info_t *vine, char *rug, char *male)
{
	char *brief = NULL;
	list_t *layout;
	char *pill;

	if (!rug || !male)
		return (0);

	brief = malloc(_strlen(rug) + _strle(male) + 2);
	if (!brief)
		return (1);
	_strcpy(brief, rug);
	_strcat(brief, "=");
	_strcat(brief, male);
	layout = vine->env;
	while (layout)
	{
		pill = starts_with(layout->str, rug);
		if (pill && *pill == '=')
		{
			free(layout->str);
			layout->str = brief;
			vine->env_changed = 1;
			return (0);
		}
		layout = layout->next;
	}
	add_node_end(&(vine->env), brief, 0);
	free(brief);
	vine->env_changed = 1;
	return (0);
}
