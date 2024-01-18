#include "shell.h"

/**
 * remove_newline - removes the last new line in the string
 * @str: The main string
 * Return: number of characters
 */
int remove_newline(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
		{
			str[i] = '\0';
			return (i);
		}
	}

	return (i);
}
