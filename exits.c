#include "shell.h"

/**
 **stringToCopy - enables to copy a string
 *@deck: where is thr copy going
 *@source: the source of the copied
 *@nim: volume of the character
 *Return: return my conccat
 */
char *stringToCopy(char *deck, char *source, int nim)
{
	int place, jan;
	char *sam = deck;

	place = 0;
	while (source[place] != '\0' && place < nim - 1)
	{
		deck[place] = source[place];
		place++;
	}
	if (place < nim)
	{
		jan = place;
		while (jan < nim)
		{
			deck[jan] = '\0';
			jan++;
		}
	}
	return (sam);
}

/**
 **stringConcat - concatenates to hub timeline
 *@deck: string one needed
 *@source: the second after the first string
 *@nim: the amount of bytes for usage
 *Return: convat sting rules
 */
char *stringConcat(char *deck, char *source, int nim)
{
	int place, jan;
	char *sam = deck;

	place = 0;
	jan = 0;
	while (deck[place] != '\0')
		place++;
	while (source[jan] != '\0' && jan < nim)
	{
		deck[place] = source[jan];
		place++;
		jan++;
	}
	if (jan < nim)
		deck[place] = '\0';
	return (sam);
}

/**
 **capum - locates a capum in string
 *@solid: we have parsed the string
 *@chair: this is the chair i was looking for
 *Return: pointer to the memory solid only
 */
char *capum(char *solid, char chair)
{
	do {
		if (*solid == chair)
			return (solid);
	} while (*solid++ != '\0');

	return (NULL);
}
