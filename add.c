#include "monty.h"

/**
 * add - add 2 nodes
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 * Return: Void.
 */
void add(stack_t **stack, unsigned int line_number)
{

	int sum = 0;
	stack_t *current = *stack;


	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	(*stack) = (*stack)->next;
	(*stack)->n = sum;
	(*stack)->prev = NULL;

	free(current);
}
