#include "monty.h"

/**
 * get_opcode - Retrieve corresponding instruction for opcode
 * @opcode: Opcode to search for
 *
 * Return: Corresponding instruction, if found, else empty instruction
 */

instruction_t get_opcode(char *opcode)
{
	int i;
	instruction_t no_instruction;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			return (opcodes[i]);
		}
	}
	no_instruction.opcode = NULL;
	no_instruction.f = NULL;

	return (no_instruction);
}

/**
 * execute_opcodes - Execute instruction associated with the opcode
 * @opcode: Opcode to execute
 * @stack: Pointer to the stack
 * @line_number: Current line number in file
 *
 * Description: The function looks up instruction associated with the opcode
 * it executes it if found. If opcode is not recognized and error message is
 * pinted to stderr and program exits with an exit code.
 *
 * Return: Nothing
 */
void execute_opcodes(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instruction = get_opcode(opcode);

	if (instruction.f)
	{
		instruction.f(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
