#ifndef MONTY_H
#define MONTY_H

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DELIMITERS " \t\n\v\f\r"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_s - singly linked list to store all lines
 * @file: file pointer
 * @line: the line to store
 * @push_int: push argument
 * @instruction: instruction to execute
 * @stack: the stack
 * @line_number: line number
 *
 * Description: global struct for the Monty program
 */
typedef struct monty_s
{
	FILE *file;
	char *line;
	int push_int;
	void (*instruction)(stack_t **stack, unsigned int line_number);
	stack_t *stack;
	unsigned int line_number;

} monty_t;

extern monty_t monty;

/* monty.c */
void init_monty(void);

/* reader.c */
void open_file(int argc, char *argv[]);
int read_line(void);

/* opcodes.c */
int extract_opcode(void);
void get_push_int(char *arg);
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);
void execute_opcode(void);

/* instrcutions.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* stack_functions.c */
stack_t *add_dnodeint(void);
stack_t *add_dnodeint_end(void);
void print_stack(void);
size_t stack_len(void);

/* cleaner.c */
void clean_resources(int is_exit);
void free_stack(void);

#endif
