#include "monty.h"

/**
 * push_op - Pushes new element to stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Parses integer from input, and creates new stack
 * The value is added on the top of stack
 *
 * Return: Nothing
 */

void push_op(stack_t **stack, unsigned int line_number)
{
	char *value = strtok(NULL, " \n\t");
	int num;
	stack_t *new_node;

	if (!value || (!isdigit(*value) && *value != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(value);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall_op - Prints all elements in stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints all elements in stack, top to bottom
 *
 * Return: Nothing
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint_op - Prints value at the top of stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints value at top of stack without removing it
 *
 * Return: Nothing
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_op - Removes top element from stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Removes top element from stack and frees memory
 *
 * Return: Nothing
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * swap_op - Swaps top two elements of stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Swaps values of the top two elements of stack
 *
 * Return: Nothing
 */

void swap_op(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * nop_op - Does nothing
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: The opcode doesn't perform any action
 * deals with no-operation instruction
 *
 * Return: Nothing
 */

void nop_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;       /* Unused parameter */
	(void)line_number; /* Unused parameter */
}
/**
 * pchar_op - Prints ASCII characteer of top value on stack
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints ASCII character of the top value on the stack.
 * If stack is empty or value is out of ASCII range,
 * prints error message, and removed top value from stack
 *
 * Return: Nothing
 */

void pchar_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
	pop_op(stack, line_number);
}

/**
 * pstr_op - Prints ASCII characters from stack as a string
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Prints ASCII characters matching values on the stack
 * from top and print character until value is 0 or stack is empty.
 *
 * Return: Nothing
 */

void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number; /*Unused parameter*/

	current = *stack;
	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
/**
 * rotl_op - Rotates stack to the top
 * @stack: Pointer to the stack
 * @line_number: Current line number in file
 *
 * Description: Moves top value of stack to the bottom, while
 * shifting the rest up.
 *
 * Return: Nothing
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	(void)line_number; /* Unused parameter */

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;

		while (first->next)
		{
			first = first->next;
		}
		(*stack)->next = NULL;
		first->next = *stack;
		second->prev = NULL;
		*stack = second;
	}
}

/**
 * rotr_op - Rotates stack to the bottom
 * @stack: Pointer to stack
 * @line_number: Current line number in file
 *
 * Description: Moves bottom value of stack to top while shifting the
 * rest down.
 *
 * Return: Nothing
 */

void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number; /* Unused parameter */

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
		{
			last = last->next;
		}

		last->prev->next = NULL;
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		*stack = last;
	}
}
