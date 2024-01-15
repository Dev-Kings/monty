#include "monty.h"

/**
 * pop - deletes item on top of stack
 * @stack: double pointer to top of stack
 * @line_number: line number of the push instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (top == NULL)
	{
		fprintf(stderr, "L%d: can\'t pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = top->prev;
	free(top);
}
