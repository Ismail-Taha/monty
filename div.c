#include "monty.h"
/**
 * f_div - f_div 2 nodes
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 * Return: Void.
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	int quotient;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = quotient;
	(*stack)->prev = NULL;
	free(temp);
}

