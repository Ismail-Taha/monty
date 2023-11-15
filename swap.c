#include "monty.h"

void swap(stack_t **stack)
{

	stack_t first = *stack;
	stack_t second = (*stack)->next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<line_number>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next != NULL)
		first->next->prev = first;

	*stack = second;
}
