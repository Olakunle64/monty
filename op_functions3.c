#include "monty.h"

/**
 * sub_top1_from_top2 - sub the top two elements of the stack
 *@stack: a double pointer to first node
 *@line_number: the current line number
 *
 * Return: void
 */

void sub_top1_from_top2(stack_t **stack, unsigned int line_number)
{
	int i = 0, num1, num2, sub_result = 0;
	stack_t *ptr = *stack;

	while (ptr)
	{
		i++;

		if (i == 2)
			break;
		ptr = ptr->next;
	}

	if (i == 2)
	{
		num1 = ptr->prev->n;
		num2 = ptr->n;
		sub_result = num2 - num1;

		*stack = ptr;
		free(ptr->prev);
		ptr = NULL;
		(*stack)->prev = NULL;
		(*stack)->n = sub_result;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_top2_by_top1 - div the top two elements of the stack
 *@stack: a double pointer to first node
 *@line_number: the current line number
 *
 * Return: void
 */

void div_top2_by_top1(stack_t **stack, unsigned int line_number)
{
	int i = 0, num1, num2, div_result = 0;
	stack_t *ptr = *stack;

	while (ptr)
	{
		i++;

		if (i == 2)
			break;
		ptr = ptr->next;
	}

	if (i == 2)
	{
		num1 = ptr->prev->n;
		num2 = ptr->n;
		if (num1 == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		div_result = num2 / num1;

		*stack = ptr;
		free(ptr->prev);
		ptr = NULL;
		(*stack)->prev = NULL;
		(*stack)->n = div_result;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}


