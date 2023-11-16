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
		f_pop(stack, line_number);
	} else if (strcmp(cmd, "swap") == 0)
	{
		f_swap(stack, line_number);
	} else if (strcmp(cmd, "add") == 0)
	{
		f_add(stack, line_number);
	} else if (strcmp(cmd, "nop") == 0)
	{
		f_nop(stack, line_number);
	} else if (strcmp(cmd, "sub") == 0)
	{
		f_sub(stack, line_number);
	} else if (strcmp(cmd, "div") == 0)
	{
		f_div(stack, line_number);
	} else if (strcmp(cmd, "mul") == 0)
        {
		f_mul(stack, line_number);
	} else if (strcmp(cmd, "mod") == 0)
	{
		f_mod(stack, line_number);
	} else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
}

