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
	}
	while ((getline(&line, &len, file)) != -1)
	{
		line_number++;
		cmd = strtok(line, " \n");
		if (cmd != NULL && cmd[0] != '#')
		{
			value = strtok(NULL, " \n");
			execute_opcode(cmd, &stack, line_number, value);
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
