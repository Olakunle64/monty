#include "monty.h"

/**
 * rotate_to_bottom - rotate the stack to bottom
 *@stack: a double pointer to first node
 *@line_number: the current line number
 *
 * Return: void
 */

void rotate_to_bottom(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || (*stack)->next == NULL)
		return;

	(void) line_number;

	temp = *stack;
	while(temp->next)
		temp = temp->next;

	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
