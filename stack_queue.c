#include "monty.h"

/**
 * f_stack - Set the stack mode.
 * @stack: Stack head (unused parameter).
 * @line_number: Line number (unused parameter).
 *
 * Return: void
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.mode = MODE_STACK;
}

/**
 * f_queue - Set the queue mode.
 * @stack: Stack head (unused parameter).
 * @line_number: Line number (unused parameter).
 *
 * Return: void
 */
void f_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.mode = MODE_QUEUE;
}
