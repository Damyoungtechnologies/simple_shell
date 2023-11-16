#include "shell.h"

/**
 * command - if it is executable
 * @vine: the info struct
 * @perk: file path only
 *
 * Return: 1 or 0
 */
int command(info_t *vine, char *perk)
{
	struct stat stunt;

	(void)vine;
	if (!perk || stat(perk, &stunt))
		return (0);

	if (stunt.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * duplicate - duplication of characters nice
 * @pathway: the string to pathway
 * @starr: index Arya
 * @skip: index stop there
 *
 * Return: pointer buffer
 */
char *duplicate(char *pathway, int starr, int skip)
{
	static char buf[1024];
	int ade = 0;
	int ola = 0;

	for (ola = 0, ade = starr; i < skip; ade++)
		if (pathway[ade] != ':')
			buf[ola++] = pathstr[ade];
	buf[ola] = 0;
	return (buf);
}

/**
 * pathfinder - finds this cmd in string
 * @vine: the vine struct
 * @pathway: the string pathway
 * @cam: the cam to find
 *
 * Return: full pathway of cam if found or NULL
 */
char *pathfinder(info_t *vine, char *pathway, char *cam)
{
	int ade = 0;
	int post = 0;
	char *pitch;

	if (!pathway)
		return (NULL);
	if ((_strlen(cam) > 2) && starts_with(cam, "./"))
	{
		if (command(vine, cam))
			return (cam);
	}
	while (1)
	{
		if (!pathway[ade] || pathway[ade] == ':')
		{
			pitch = duplicate(pathway, post, ade);
			if (*pitch == NULL)
				_strcat(pitch, cam);
			else
			{
				_strcat(pitch, "/");
				_strcat(pitch, cam);
			}
			if (command(vine, pitch))
				return (pitch);
			if (pathway[ade] == NULL)
				break;
			post = ade;
		}
		ade++;
	}
	return (NULL);
}
