#include "monty.h"

/**
 * extract_opcode - extracts the opcode from the current line of the Monty file
 *
 * Return: 0 on success, 1 if line is empty
 */
int extract_opcode(void)
{
	char *opcode = strtok(monty.line, DELIMITERS);
	char *arg;

	if (!opcode)
		return (1);

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, DELIMITERS);
		get_push_int(arg);
	}

	monty.instruction = get_opcode(opcode);

	return (0);
}

/**
 * get_push_int - gets the integer to be pushed onto the stack
 * @arg: the argument string to be converted to an integer
 */
void get_push_int(char *arg)
{
	char *endptr;
	int integer;

	if (arg)
		integer = strtol(arg, &endptr, 10);

	if (!arg || *endptr)
	{
		fprintf(stderr, "L%d: usage: push integer\n", monty.line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	monty.push_int = integer;
}

/**
 * get_opcode - retrieves the function associated with the given opcode
 * @opcode: the opcode to be matched
 *
 * Return: pointer to the appropriate function, or NULL if no match is found
 */
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instrs[] = {{"push", push}, {"pall", pall}, {"pint", pint},
							  {"pop", pop},	  {"swap", swap}, {"nop", nop},
							  {NULL, NULL}};

	int i;

	for (i = 0; instrs[i].opcode; i++)
		if (strcmp(opcode, instrs[i].opcode) == 0)
			return (instrs[i].f);

	fprintf(stderr, "L%d: unknown instruction %s\n", monty.line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * execute_opcode - executes the current opcode functions
 */
void execute_opcode(void)
{
	if (monty.instruction)
		monty.instruction(&(monty.stack), monty.line_number);
}
