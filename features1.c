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

	if (!*stack)
		return;

	(void) line_number;
	temp1 = (*stack)->next;
	(*stack)->next = NULL;
	(*stack)->prev = temp1;
	temp2 = temp1;

	while (temp2)
	{
		temp1 = temp1->next;
		temp2->next = (*stack);
		temp2->prev = temp1;
		(*stack) = temp2;
		temp2 = temp1;
	}

}
