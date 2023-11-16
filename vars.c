#include "shell.h"

/**
 * chain - test to know the chain in the buffer
 * @vine: the structure parameter
 * @bluff: character for the buffer
 * @per: buffers current address
 *
 * Return: 1 or 0
 */
int chain(info_t *vine, char *bluff, size_t *per)
{
	size_t john = *per;

	if (bluff[john] == '|' && bluff[john + 1] == '|')
	{
		bluff[john] = 0;
		john++;
		vine->cmd_buf_type = CMD_OR;
	}
	else if (bluff[john] == '&' && bluff[john + 1] == '&')
	{
		bluff[john] = 0;
		john++;
		vine->cmd_buf_type = CMD_AND;
	}
	else if (bluff[john] == ';') /* found end of this command */
	{
		bluff[john] = 0; /* replace semicolon with null */
		vine->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*per = john;
	return (1);
}

/**
 * check - continuous chaining status
 * @vine: the parameter structural language shout
 * @bluff: the character buffering alone
 * @per: address of position in the buffer.thanks
 * @ade: starting in buf pattern
 * @tenal: length of our common
 *
 * Return: Void
 */
void check(info_t *vine, char *bluff, size_t *per, size_t ade, size_t tenal)
{
	size_t john = *per;

	if (vine->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			bluff[ade] = 0;
			john = tenal;
		}
	}
	if (ade->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			bluff[ade = 0];
			john = len;
		}
	}

	*p = john;
}

/**
 * alliancerep - replaces an aliases in the tokenized string
 * @vine: vine informst struct
 *
 * Return: 1 or 0
 */
int alliancerep(info_t *vine)
{
	int ade;
	list_t *layout;
	char *per;

	for (ade = 0; ade < 10; ade++)
	{
		layout = node_starts_with(vine->alias, vine->argv[0], '=');
		if (layout == NULL)
			return (0);
		free(vine->argv[0]);
		per = _strchr(layout->str, '=');
		if (per == NULL)
			return (0);
		per = _strdup(per + 1);
		if (per == NULL)
			return (0);
		vine->argv[0] = per;
	}
	return (1);
}

/**
 * variancerep - replaces vars in the token
 * @vine: the vine parametet
 *
 * Return: 1 or 0
 */
int variancerep(info_t *vine)
{
	int ade = 0;
	list_t *layout;

	for (ade = 0; vine->argv[ade]; ade++)
	{
		if (vine->argv[ade][0] != '$' || !vine->argv[ade][1])
			continue;

		if (!_strcmp(vine->argv[ade], "$?"))
		{
			replace_string(&(vine->argv[ade]),
				_strdup(convert_number(vine->status, 10, 0)));
			continue;
		}
		if (!_strcmp(vine->argv[ade], "$$"))
		{
			replace_string(&(vine->argv[ade]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		layout = node_starts_with(vine->env, &vine->argv[ade][1], '=');
		if (layout)
		{
			replace_string(&(vine->argv[ade]),
				_strdup(_strchr(layout->str, '=') + 1));
			continue;
		}
		replace_string(&vine->argv[ade], _strdup(""));

	}
	return (0);
}

/**
 * stringrep - replaces my string as always
 * @older: address of the oldman
 * @newer: newer string
 *
 * Return: 1 or 0
 */
int stringrep(char **older, char *newer)
{
	free(*older);
	*older = newer;
	return (1);
}
