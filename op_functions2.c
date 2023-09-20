#include "monty.h"

/**
 * _add - add the top two element on the stack
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->n += current->n;
	free(current);
}
