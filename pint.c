#include "monty.h"

/**
 * pint - prints number at top of stack
 * @stack: double pointer to top of stack
 * @line_number: line number of the push instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;

	if (top != NULL)
	{
		printf("%d\n", top->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
