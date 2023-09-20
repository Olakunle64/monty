#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char *op_code[];
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
void monty_interpreter(unsigned int line_number, stack_t **stack);
void tokenize_line(char *buf);
void read_file(char lines[][100], stack_t **stack, unsigned int line_count);
void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void free_list(stack_t *head);
void div_top2_by_top1(stack_t **stack, unsigned int line_number);
void sub_top1_from_top2(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void rotate_to_bottom(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
