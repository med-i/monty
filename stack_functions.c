#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of the stack
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint()
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = monty.push_int;
	new->next = monty.stack;
	new->prev = NULL;

	if (monty.stack)
		monty.stack->prev = new;

	monty.stack = new;

	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end()
{
	stack_t *current = monty.stack;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = monty.push_int;
	new->next = NULL;

	if (current)
	{
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
	else
	{
		new->prev = NULL;
		monty.stack = new;
	}

	return (new);
}

/**
 * print_stack - prints the stack
 */
void print_stack(void)
{
	stack_t *current = monty.stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
