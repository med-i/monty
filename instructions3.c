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
}

/**
 * pchar  - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int code;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	// 64 -- 90  |  97 -- 122

	code = (*stack)->n;

	if ((code >= 64 && code <= 90) || (code >= 97 && code <= 122))
		printf("%c\n", (char)code);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}
}
