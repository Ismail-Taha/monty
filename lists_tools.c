#include "monty.h"

/**
 * free_stack - Frees a dlistint_t linked list.
 * @stack: List head.
 *
 * Return: void.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
