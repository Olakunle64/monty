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
	stack_t *temp1, *temp2;

	if (!*stack || (*stack)->next == NULL)
		return;

	(void) line_number;

	temp1 = *stack;
	while(temp1->next)
		temp1 = temp1->next;

	temp2 = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp2->next = NULL;
	temp1->next = temp2;
	temp2->prev = temp1;
}
