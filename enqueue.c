#include "monty.h"

/**
 *stack_op - A function that sets the format of the data to a stack (LIFO)
 *@stack: a pointer to the pointer to the top node of stack
 *@line_number:line number where the function action or error occurs
 *
 *Return: (void)
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */
	(void)stack;       /* Unused parameter */
    /*This opcode doesn't require any action as stack is the default mode*/
}


/**
 *queue_op - Function that sets the format of the data to a queue (FIFO)
 *@stack: a pointer to the pointer to the top node of stack
 *@line_number:line number where the function action or error occurs
 *
 *Return: nothing
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number; /* Unused parameter */

    /* If the stack is empty or contains only one element, no need to switch */
	if (!*stack || !(*stack)->next)
		return;

	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	/**
	 * Switching mode: The top of the stack becomes the front of the queue
	 * and the front of the queue becomes the top of the stack
	 */
	(*stack)->prev = last;
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
