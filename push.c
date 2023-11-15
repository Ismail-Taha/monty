#include "monty.h"
/**
 * f_push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_push(stack_t **stack,  unsigned int line_number, char *value)
{
        stack_t *new_node;
	int number;

	if (atoi(value) == 0 && strcmp(value , "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
	}
	number = atoi(value);

        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = number;
        new_node->prev = NULL;
        new_node->next = *stack;
        if ((*stack) != NULL)
                (*stack)->prev = new_node;
        *stack = new_node;
}
