#include "monty.h"

/**
 * f_pall - function that prints the stack
 * @stack: stack head
 * @line_number: no used
 * Return: no return
*/
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
