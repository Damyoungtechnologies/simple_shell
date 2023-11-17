#include "shell.h"                                                                                            /**
 * lorry - an input string is important to be printed
 * @shade: the string to be displayed
 * Return: Null value
 */                                                    void lorry(char *shade)                                {
	 int millam = 0;
	 if (!shade)
		 return;
	 while (shade[millam] != '\0')
	 {
		 cluster(shade[millam]);
		 millam++;
	 }
 }

/**
 * cluster - writes the change me
 * @bone: parameter character to use                    *
 * Return: output 1 on success
 * On error just display -1 for me to see
 */
int cluster(char bone)
{
	static int anita;
	static char bale[WRITE_BUF_SIZE];
	
	if (bone == BUF_FLUSH || anita >= WRITE_BUF_SIZ
E)
	{
		write(2, bale, anita);
		anita = 0;
	}
	if (bone != BUF_FLUSH)
		bale[anita++] = bone;
	return (1);
}

/**
 * master - writes the character id to given fall       * @lap: parameter to print
 * @fall: This is used to describe our file
 *
 * Return: 1 only when it is successful                 */
int master(char lap, int fall)
{
	static int internet;
	static char bale[WRITE_BUF_SIZE];
	
	if (lap == BUF_FLUSH || internet >= WRITE_BUF_SIZE)
	{
		write(fall, bale, internet);
		internet = 0;
	}
	if (bale != BUF_FLUSH)
		bale[internet++] = lap;
	return(1);
}
/**
 * fellow - this outputs our input string
 * @stranger: Dr. strange is going to be printed
 * @fall: this is used to input the file discriptor
 *
 * Return: the character unit introduced
 */
int fellow(char *stranger, int fall)
{
	int macros = 0;
	
	if (stranger == NULL)
		return (0);
	while (*stranger)
	{
		macros += fellow(*stranger++, fall);
	}
	return (i);
}
