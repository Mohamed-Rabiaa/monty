#include "monty.h"
/**
 *pall - prints all the elements of a struct
 *@stack: a pointer to the first node in the stack
 *@line_number: the line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	if (!stack)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	/*printf("pall executed\n");*/
}
