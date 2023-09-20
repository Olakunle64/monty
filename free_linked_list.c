#include "monty.h"

/**
 * free_list -  a function that frees  a doubly linked list.
 *@head: a pointer to the head of th list
 *
 * Return: void
 */

void free_list(stack_t *head)
{
	stack_t *ptr = head, *ptr_2;

	if (head == NULL)
		return;
	while (ptr)
	{
		ptr_2 = ptr->next;
		free(ptr);
		ptr = ptr_2;
	}
}
