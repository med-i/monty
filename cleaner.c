#include "monty.h"

/**
 * clean_resources - cleans up memory and file resources
 * @is_exit: flag indicating the program is terminating
 */
void clean_resources(int is_exit)
{
	if (monty.line)
	{
		free(monty.line);
		monty.line = NULL;
	}

	if (is_exit)
	{
		fclose(monty.file);
		if (monty.stack)
			free_stack();
	}
}

/**
 * free_stack - frees the stack
 */
void free_stack(void)
{
	stack_t *temp = monty.stack;

	while (monty.stack)
	{
		temp = monty.stack;
		monty.stack = monty.stack->next;
		free(temp);
	}
}
