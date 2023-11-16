#include "monty.h"

/**
 * f_push - add node to the stack
 * @stack: stack head
 * @line_number: line_count
 * @value: value to be added
 * Return: no return
*/

void f_push(stack_t **stack, unsigned int line_number, const char *value)
{
	int num;
	stack_t *new_node, *current;

	if (value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(value);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	if (global.mode == MODE_STACK || *stack == NULL)
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	} else
	{
		new_node->next = NULL;
		current = *stack;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}
}
