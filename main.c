#include "monty.h"


int main(int argc, char **argv) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    char *cmd, *value;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((getline(&line, &len, file)) != -1) {
        cmd = strtok(line, " \n");
        if (cmd == NULL) continue;

        value = strtok(NULL, " \n");
        line_number++;

        if (strcmp(cmd, "push") == 0) {
            if (value == NULL) {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            f_push(&stack, line_number, value);
        } else if (strcmp(cmd, "pall") == 0) {
            f_pall(&stack, line_number);
        } else if (strcmp(cmd, "pint") == 0) {
            pint(&stack, line_number);
        }
    }

    free(line);
    fclose(file);
    return 0;
}

