#include "monty.h"

/**
 * pall - adds an item onto a stack
 * @stack: double pointer to top of stack
 * @line_number: line number of the push instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
