#include "monty.h"
/**
 *search_opcode - searches for opcode in inst array
 *@opcode: the opcode to search
 *@inst: the inst array to search in
 *@line_num: the line number
 *
 *Return: a pointer to the function to hanle the opcode
 */
void (*search_opcode(char *opcode, unsigned int line_num))
(stack_t **stack, unsigned int line_num)
{
	int i = 0;
	void (*f)(stack_t **, unsigned int);

	instruction_t inst_arr[] = {{"push", push}, {"pall", pall},
				{"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				  {NULL, NULL}
	};
	(void) line_num;
	while (i < 2)
	{
		if (strcmp(inst_arr[i].opcode, opcode) == 0)
		{
			f = inst_arr[i].f;
			return (f);
		}
		i++;
	}
	return (NULL);
}
