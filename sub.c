#include "monty.h"

/**
 * f_sub - sub 2 nodes
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 * Return: Void.
 */
void f_sub(stack_t **stack, unsigned int line_number)
{

	int sub = 0;
	stack_t *current = *stack;


	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;

	(*stack) = (*stack)->next;
	(*stack)->n = sub;
	(*stack)->prev = NULL;

	free(current);
}
