#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the script where this opcode appears.
 *
 * Return: void.
 */
void f_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;
	(void) line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	bottom = *stack;

	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	*stack = bottom;
}
