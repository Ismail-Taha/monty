#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the script where this opcode appears.
 *
 * Return: void.
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
