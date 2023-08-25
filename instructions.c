#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (!add_dnodeint())
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_resources(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	print_stack();
}
