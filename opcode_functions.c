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
	strip_extra_characters(cmd);
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
		f_swap(stack, line_number);
	else if (strcmp(cmd, "add") == 0)
		f_add(stack, line_number);
	else if (strcmp(cmd, "nop") == 0)
		f_nop(stack, line_number);
	else if (strcmp(cmd, "sub") == 0)
		f_sub(stack, line_number);
	else if (strcmp(cmd, "div") == 0)
		f_div(stack, line_number);
	else if (strcmp(cmd, "mul") == 0)
		f_mul(stack, line_number);
	else if (strcmp(cmd, "mod") == 0)
		f_mod(stack, line_number);
	else if (strcmp(cmd, "pchar") == 0)
		f_pchar(stack, line_number);
	else if (strcmp(cmd, "pstr") == 0)
		f_pstr(stack, line_number);
	else if (strcmp(cmd, "rotl") == 0)
		f_rotl(stack, line_number);
	else if (strcmp(cmd, "rotr") == 0)
		f_rotr(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
}

/**
 * strip_extra_characters - Removes non-alphanumeric characters from a string.
 * @str: Input string to be processed and modified.
 *
 * Return: Void.
 */
void strip_extra_characters(char *str)
{
	int i, j = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isalnum((unsigned char)str[i]))
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}
