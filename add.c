#include "monty"


void add(stack_t **stack, int line_number)
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
