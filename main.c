#include "monty.h"

stack_t *stack = NULL;
void handle_opcode(stack_t **stack, unsigned int line_number);
void (*search_opcode(char *opcode, instruction_t *inst, unsigned int line_num))
(stack_t **stack, unsigned int line_num);

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
	instruction_t inst[10];
	void (*f)(stack_t **, unsigned int);
	char **line_toks;
	char *line = NULL;
	char *opcode = NULL;
	size_t len = 0;
	unsigned int line_num = 1;
	/*int arg;*/

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
	inst[0].opcode = "push";
	inst[0].f = push;

	inst[1].opcode = "pall";
	inst[1].f = pall;

	while (getline(&line, &len, fp) != -1)
	{
		remove_newline(line);
		if (_strchr(line, ' '))
		{
			line_toks = _strtok(line, ' ');
			opcode = line_toks[0];
			/*arg = atoi(line_toks[1]);*/
		}
		else
			opcode = line;
		f = search_opcode(opcode, inst, line_num);
		if (f == NULL)
			fprintf(stderr, "L%d: unknown instruction %s\n",
				line_num, opcode);
		else
			(*f)(&stack, line_num);
		line_num++;
	}
	return (0);
}


/**
 *search_opcode - searches for opcode in inst array
 *@opcode: the opcode to search
 *@inst: the inst array to search in
 *@line_num: the line number
 *
 *Return: a pointer to the function to hanle the opcode
 */
void (*search_opcode(char *opcode, instruction_t *inst, unsigned int line_num))
(stack_t **stack, unsigned int line_num)
{
	int i = 0;

	void (*f)(stack_t **, unsigned int);

	(void) line_num;
	while (i < 2)
	{
		if (strcmp(inst[i].opcode, opcode) == 0)
		{
			f = inst[i].f;
			return (f);
		}
		i++;
	}
	return (NULL);
}
