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

/**
 * pint - prints the valuer at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (!monty.stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", monty.line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", monty.stack->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_t *to_delete;

	if (!monty.stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", monty.line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	to_delete = monty.stack;
	monty.stack = monty.stack->next;
	free(to_delete);
}
