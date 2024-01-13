#include "monty.h"

char *cmd = NULL;

/**
 * main - Monty intepreter.
 * @argc: argument count
 * @argv: array of arguments
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i = 0;
	int linenumber = 0;
	FILE *file;
	char linecmd[50];
	/* char *cmd; */
	size_t cmd_length;
	stack_t *stack = NULL;
	char cmdfunction[4];
	instruction_t *instructions;

	file = fopen((char *)argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can\'t open file %s\n", (char *)argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (fgets(linecmd, sizeof(linecmd), file) != NULL)
		{
			cmd_length = strlen(linecmd);
			cmd = malloc(cmd_length	+ 1);
			if (cmd == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			linenumber++;
			strncpy(cmd, linecmd, cmd_length);
			cmd[cmd_length] = '\0';
			instructions = malloc(sizeof(instruction_t) * 3);
			if (instructions == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}

			instructions[0].opcode = "push";
			instructions[0].f = push;
			instructions[1].opcode = "pall";
			instructions[1].f = pall;
			instructions[2].opcode = NULL;
			instructions[2].f = NULL;

			while (instructions[i].opcode != NULL)
			{
				strncpy(cmdfunction, cmd, 4);
				cmdfunction[4] = '\0';
				if (strcmp(cmdfunction, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, linenumber);
					break;
				}
				i++;
			}

			if (instructions[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						linenumber, cmd);
				exit(EXIT_FAILURE);
			}
			free(cmd);
		}
	}
	fclose(file);

	return (0);
}
