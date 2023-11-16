#include "shell.h"

/**
 * stringCopy - copy this string
 * @destle: the first string
 * @source: the second
 * Return: pointer to return
 */
char *stringCopy(char *destle, char *source)
{
	int ale = 0;

	if (destle == source || source == 0)
		return (destle);
	while (source[ale])
	{
		destle[ale] = source[ale];
		ale++;
	}
	destle[ale] = 0;
	return (destle);
}

/**
 * stringDupe - duplication of your string up
 * @string: to duplicate a string
 *
 * Return: pointer the duplicated string
 */
char *stringDupe(const char *string)
{
	int relent = 0;
	char *circus;

	if (!string)
		return (NULL);
	while (*string++)
		relent++;
	circus = malloc(sizeof(char) * (relent + 1));
	if (circus == NULL)
		return (NULL);
	for (relent++; relent--;)
		circus[relent] = *--string;
	return (circus);
}

/**
 * putString - put string down below
 * @strong: the string is going to be printed
 *
 * Return: Just Nothing
 */
void putString(char *strong)
{
	int ale = 0;

	if (strong == NULL)
		return;
	while (strong[ale] != '\0')
	{
		putCharacter(strong[ale]);
		ale++;
	}
}

/**
 * putCharacter - writes the char to only stdout
 * @character: print just character
 *
 * Return: On success 1, otherwise -1
 */
int putCharacter(char character)
{
	static int ale;
	static char bluff[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || ale >= WRITE_BUF_SIZE)
	{
		write(1, bluff, ale);
		ale = 0;
	}
	if (character != BUF_FLUSH)
		bluff[ale++] = character;
	return (1);
}
