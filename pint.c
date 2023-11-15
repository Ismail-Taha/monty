#include "monty.h"
/**
 * f_pint - function that prints the top
 * @stack: stack head
 * @line_number: line counter
 * Return: no return
*/
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
