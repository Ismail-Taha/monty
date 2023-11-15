#include "monty.h"

/**
 * execute_opcode - Executes the corresponding Monty opcode.
 * @cmd: Monty opcode to be executed.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 * @value: Value (for "push" instruction).
 * Return: Void.
 */
void execute_opcode(char *cmd, stack_t **stack,
	unsigned int line_number, char *value)
{
	if (strcmp(cmd, "push") == 0)
	{
		f_push(stack, line_number, value);
	} else if (strcmp(cmd, "pall") == 0)
	{
		f_pall(stack, line_number);
	} else if (strcmp(cmd, "pint") == 0)
	{
		f_pint(stack, line_number);
	} else if (strcmp(cmd, "pop") == 0)
	{
		pop(stack, line_number);
	} else if (strcmp(cmd, "swap") == 0)
	{
		swap(stack, line_number);
	} else if (strcmp(cmd, "add") == 0)
	{
		add(stack, line_number);
	} else if (strcmp(cmd, "nop") == 0)
	{
		nop(stack, line_number);
	} else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
}

