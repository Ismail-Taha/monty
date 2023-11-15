#include "monty.h"

/**
 * main - Entry point for the Monty language interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on successful execution.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	char *cmd, *value;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	} while ((getline(&line, &len, file)) != -1)
	{
		cmd = strtok(line, " \t\n$");
		if (cmd == NULL)
			continue;
		value = strtok(NULL, " \t\n$");
		line_number++;
		if (strcmp(cmd, "push") == 0)
		{
			if (value == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			f_push(&stack, line_number, value);
		} else if (strcmp(cmd, "pall") == 0)
		{
			f_pall(&stack, line_number);
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
