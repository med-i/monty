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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	size_t size = stack_len();

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * from the second top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	size_t size = stack_len();

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	size_t size = stack_len();

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	size_t size = stack_len();

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}
