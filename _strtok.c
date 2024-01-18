#include "monty.h"

/**
 * _strtok - splits a string into words.
 * @str: the strings
 * @delim: a delimiter
 * Return: pointer to a new string, or NULL if it fails
 */

char **_strtok(char *str, char delim)
{
	int i, j, k, word_count;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (i = 0, word_count = 0; str[i] != '\0'; i++)
	{
		if (str[i] != delim && (i == 0 || str[i - 1] == delim))
			word_count++;
	}
	if (word_count == 0)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);
	for (i = 0, word_count = 0; str[i] != '\0'; i++)
	{
		if (str[i] != delim && (i == 0 || str[i - 1] == delim))
		{
			for (j = i; str[j] != '\0' && str[j] != delim; j++)
				;
			words[word_count] = (char *)malloc(sizeof(char) * (j - i + 1));
			if (words[word_count] == NULL)
			{
				for (; word_count >= 0; word_count--)
					free(words[word_count]);
				if (words)
					free(words);
				return (NULL);
			}
			for (k = 0; i < j; i++, k++)
				words[word_count][k] = str[i];
			words[word_count][k] = '\0';
			word_count++;
		}
	}
	words[word_count] = NULL;

	return (words);
}

