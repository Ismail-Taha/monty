#include "monty.h"
/**
 * f_rotl - Rotates the stack to the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the script where this opcode appears.
 * Description: The top element of the stack becomes the last one,
 *              and the second top element of the stack becomes the first one.
 *              rotl never fails.
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;
	(void) line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	bottom = *stack;

	while (bottom->next != NULL)
		bottom = bottom->next;

	*stack = top->next;
	(*stack)->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}
