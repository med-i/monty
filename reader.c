#include "monty.h"

/**
 * open_file - opens the Monty bytecode file
 * @argc: the number of arguments
 * @argv: the array of arguments
 */
void open_file(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty.file = fopen(argv[1], "r");
	if (!monty.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_line - reads a line from the Monty file
 *
 * Return: the number of characters read
 */
int read_line(void)
{
	size_t len = 0;
	ssize_t read;

	read = getline(&monty.line, &len, monty.file);
	if (read == -1 && !feof(monty.file))
	{
		clean_resources(1);
		fprintf(stderr, "Error: Can't read from file\n");
		exit(EXIT_FAILURE);
	}

	if (read > 0 && monty.line[read - 1] == '\n')
	{
		monty.line[read - 1] = '\0';
		read--;
	}

	return (read);
}
