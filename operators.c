#include "monty.h"

/**
 *add_op - Function that adds top two elements of a stack
 *@stack: a double pointer to the top node of stack
 *@line_number:line number where the function action or error occurs
 *
 * Return: nothing
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop_op(stack, line_number);
}



/**
 *sub_op- Function that subtracts top stack element from the second top
 *@stack: a double pointer to the top node of stack
 *@line_number:line number where the function action or error occurs
 *
 *Return: nothing
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop_op(stack, line_number);
}


/**
 *div_op - Function dividing the second top element by top stack element
 *@stack: a double pointer to the top node of stack
 *@line_number:line number where the function action or error occurs
 *
 *Return: nothing
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop_op(stack, line_number);
}


/**
 *mul_op - Funtion that multiplies 2nd top with the top stack element
 *@stack: a double pointer to the top node of stack
 *@line_number:line number where the function action or error occurs
 *
 *Return: nothing
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop_op(stack, line_number);
}


/**
 *mod_op - computes rest of division of 2nd element by the top one
 *@stack: a double pointer to the top node of stack
 *@line_number:line number where the function action or error occurs
 *
 *
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop_op(stack, line_number);
}
