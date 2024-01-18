#include "monty.h"
/**
 *push - adds a new node at the beginning of a struct.
 *@stack: a pointer to the pointer of the first node in the struct
 *@line_num: the line number
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;

	if (!stack)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_num;
	new->next = NULL;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
	/*printf("push executed\n");*/
}
