#include "monty.h"

/**
 * print_str - print numbers in stack as string
 *@stack: a double pointer to first node
 *@line_number: the current line number
 *
 * Return: void
 */

void print_str(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *ptr = *stack;
	char str[1024] = {'\0'};
	char ch = 65;  /* initialize to ascii code of A */

	(void) line_number;

	i = 0;
	while (ptr && ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)))
	{
		ch = ptr->n;
		str[i] = ch;
		ptr = ptr->next;
		i++;
	}

	printf("%s\n", str);
}

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

