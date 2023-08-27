#include "monty.h"

monty_t monty;

/**
 * init_monty - initializes the global Monty structure
 */
void init_monty(void)
{
	monty.file = NULL;
	monty.line = NULL;
	monty.push_int = -1;
	monty.instruction = NULL;
	monty.stack = NULL;
	monty.line_number = 1;
}

/**
 * main - entry point of the monty program
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	init_monty();
	open_file(argc, argv);

	while (read_line() != -1)
	{
		if (extract_opcode())
		{
			clean_resources(0);
			monty.line_number++;
			continue;
		}

		execute_opcode();

		monty.line_number++;
		clean_resources(0);
	}

	clean_resources(1);
	return (EXIT_SUCCESS);
}
