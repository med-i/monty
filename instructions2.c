#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void add(stack_t **stack, unsigned int line_number)
{
	size_t size = stack_len();

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - doesn’t do anything
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
