#include "monty.h"

/**
 * push - adds an item onto a stack
 * @stack: double pointer to top of stack
 * @line_number: line number of the push instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new, *head;

	head = *stack;

	if (!is_integer(cmd))
	{
		fprintf(stderr, "L%u:R usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(cmd + 5);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new-> n = num;
	new->next = NULL;

	if (head == NULL)
	{
		new->prev = NULL;
	}
	else
	{
		new->prev = head;
	}
	
	*stack = new;
}
