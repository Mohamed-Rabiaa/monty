#include "monty.h"

stack_t *stack = NULL;

/**
 * main - check the code
 *@ac: the number of arguments
 *@av: the arguemnts
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	FILE *fp;
	char *line;
	size_t len = 0;
	unsigned int line_num = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, fp) != -1)
	{
		remove_newline(line);
		execute_opcode(line, line_num);
	}
	fclose(fp);
	return (0);
}
