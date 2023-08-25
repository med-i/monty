#include "monty.h"

/**
 * nop - doesn’t do anything
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	clean_resources(0);
}
