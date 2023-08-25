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
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
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

	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		clean_resources(0);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack_len() < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		clean_resources(1);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
