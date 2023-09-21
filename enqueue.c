#include "monty.h"

/**
 * _enqueue - enqueue an element on the queue
 * @stack: the pointer to the first node
 * @line_number: the line number of the opcode
 *
 * Return: void.
 */
void _enqueue(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode, *current;
	int number, i = 0;

	if (!op_code[1])
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	while (op_code[1][i] != '\0')
	{
		if (!(isdigit(op_code[1][i]) || op_code[1][0] == '-'))
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
	current = *stack;
	newnode->n = number;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (current == NULL)
	{
		*stack = newnode;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = newnode;
	newnode->prev = current;
}
