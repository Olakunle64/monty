#include "monty.h"

/**
 * _push - push an element on the stack
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	int number, i = 0;

	if (!op_code[1])
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	while (op_code[1][i] != '\0')
	{
		if (!(isdigit(op_code[1][i]) || op_code[1][0] == '-'
					|| op_code[1][0] == '+'))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = atoi(op_code[1]);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	newnode->n = number;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*stack == NULL)
	{
		*stack = newnode;
		return;
	}
	newnode->next = *stack;
	(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 * _pall - print all the element of the stack
 * @stack: a double pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL)
	{
		return;
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - print the value at the top of the stack followed by a newline
 * @stack: a double pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: a double pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	current = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(current);
}

/**
 * _swap - swap the two two element of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
