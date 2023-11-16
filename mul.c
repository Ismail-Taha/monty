#include "monty.h"
/**
 * f_mul - multiply 2 nodes
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 * Return: Void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = product;
	(*stack)->prev = NULL;
	free(temp);
}

