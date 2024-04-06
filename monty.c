#include "monty.h"

instruction_t opcodes[] = {
	{"push", push_op},
	{"pall", pall_op},
	{"pint", pint_op},
	{"pop", pop_op},
	{"swap", swap_op},
	{"add", add_op},
	{"sub", sub_op},
	{"div", div_op},
	{"mul", mul_op},
	{"mod", mod_op},
	{"pchar", pchar_op},
	{"pstr", pstr_op},
	{"rotl", rotl_op},
	{"rotr", rotr_op},
	{"nop", nop_op},
	{NULL, NULL}
};

/**
 *main - This is the entry point of the monty interpreter.
 * The function first checks the No of arguments passed. If it they
 * are exactly 2, it calls the read_and_process function to get
 * instructions from appropriate files. If they are not exactly 2,
 * it prints a failure message and exits
 *
 *@argc: No of command-line arguments entered into the program
 *@argv: An an array of the command line arguments
 *
 *Return:
 *      EXIT_SUCCESS if instructions are passed appropriately
 *      EXIT_FAILURE if argument count is incorrect among other errors
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	read_and_process_file(argv[1]);
	return (EXIT_SUCCESS);
}
