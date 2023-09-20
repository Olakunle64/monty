#include "monty.h"

/**
 * _mul - multiply the top two element on the stack
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n *= current->n;
	free(current);
}

/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n %= current->n;
	free(current);
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->n >= 0 && (*stack)->n <= 127))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (*stack == NULL)
		putchar('\n');
	else
	{
		while (current != NULL && !(current->n <= 0 || current->n > 127))
		{
			putchar(current->n);
			current = current->next;
		}
		putchar('\n');
	}
}

/**
 * _rotl - rotates the stack to the top
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp = current->n;
	(void)line_number;

	while (current != NULL)
	{
		if (current->next == NULL)
			current->n = temp;
		else
			current->n = current->next->n;
		current = current->next;
	}
}
