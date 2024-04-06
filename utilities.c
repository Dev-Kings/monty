#include "monty.h"

/**
 * strip_whitespace - function that removes leading spaces/tabs from string
 * @line: double pointer to a character on the string
 *
 * Return: nothing
 */
void strip_whitespace(char **line)
{
	while (**line == ' ' || **line == '\t')
	{
		(*line)++;
	}
}


/**
 *strip_trailing_whitespace - function removing whitespaces from end of strings
 *@line: a pointer to the characters on string
 *
 *Return: nothing
 */
void strip_trailing_whitespace(char *line)
{
	char *end = line + strlen(line) - 1;

	while (end > line && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		end--;
	}

	*(end + 1) = '\0';
}


/**
 *remove_dollar_sign - function that removes $-sign at the end of string
 *@line: a pointer to character string to be modified
 *
 *Return: nothing
 */
void remove_dollar_sign(char *line)
{
	char *end = line + strlen(line) - 1;

	if (end >= line && *end == '$')
	{
		*end = '\0';
	}
}


/**
 *process_line - Function that process line of code by trimming leading..
 *and trailing whitespace characters from lines. Also handles comments
 *@stack: pointer to the pointer to the top node of stack
 *@format: Represent the data format either Stack or Queue
 *@line: Input line of code that is to be processed
 *@line_number:line number where the function action or error occurs
 *
 * Return: void
 */
void process_line(stack_t **stack, data_format format, char *line,
		unsigned int line_number)
{
	char *opcode;

	strip_whitespace(&line);
	if (*line == '#' || *line == '\n')
	{
		return;
	}
	strip_trailing_whitespace(line);
	remove_dollar_sign(line);
	opcode = strtok(line, " ");
	if (opcode)
	{
		if (strcmp(opcode, "stack") == 0)
		{
			format = STACK;
		}
		else if (strcmp(opcode, "queue") == 0)
		{
			format = QUEUE;
		}
		else
		{
			execute_opcodes(opcode, stack, line_number);
			if (format == QUEUE && *stack && (*stack)->next)
			{
				stack_t *last = *stack;

				while (last->next)
				{
					last = last->next;
				}
				last->prev->next = NULL;
				last->next = *stack;
				(*stack)->prev = last;
				last->prev = NULL;
				*stack = last;
			}
		}
	}
}


/**
 *read_and_process_file - function that reads lines from input
 *and processes each command
 *@filename: Name of the file with instructions
 i*
 *Return: void
 */

void read_and_process_file(const char *filename)
{
	stack_t *stack = NULL, *tmp;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	data_format format = STACK; /* Default data format */
	FILE *file;

	file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		process_line(&stack, format, line, line_number);
	}

	free(line);
	fclose(file);

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
