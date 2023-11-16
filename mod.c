#include "monty.h"
/**
 * f_mod - modulation of  2 nodes
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 * Return: Void.
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	int remainder;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = remainder;
	(*stack)->prev = NULL;
	free(temp);
}

