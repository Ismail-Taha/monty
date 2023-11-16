#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * mode_e - Enumeration for stack modes.
 * @MODE_STACK: Stack mode.
 * @MODE_QUEUE: Queue mode.
 *
 * Description: Enumerates the different modes for handling a stack.
 */
typedef enum monty_mode_e
{
	MODE_STACK,
	MODE_QUEUE
} monty_mode_t;

/**
 * global_structure - Global structure for maintaining stack modes and other variables.
 * @mode: Current stack mode (MODE_STACK or MODE_QUEUE).
 *
 * Description: Defines a global structure to hold variables that need to be accessed across functions.
 * The primary purpose is to store the current stack mode.
 */
typedef struct global_structure
{
	mode_t mode;
} global_structure;

global_structure global;
/* Function Prototypes */
void f_push(stack_t **stack, unsigned int line_number, const char *value);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);
void f_sub(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);
void f_mul(stack_t **stack, unsigned int line_number);
void f_mod(stack_t **stack, unsigned int line_number);
void f_pchar(stack_t **stack, unsigned int line_number);
void f_pstr(stack_t **stack, unsigned int line_number);
void f_rotl(stack_t **stack, unsigned int line_number);
void f_rotr(stack_t **stack, unsigned int line_number);
void f_stack(stack_t **stack, unsigned int line_number);
void f_queue(stack_t **stack, unsigned int line_number);
/* main entry point */
int main(int argc, char **argv);

void execute_opcode(char *cmd, stack_t **stack, unsigned int line_number, char *value);
void strip_extra_characters(char *str);

/** dlinked lists function 
stack_t *queue_add(stack_t **stack, const int n);
stack_t *stack_add(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
*/
void free_stack(stack_t *stack);

#endif /* MONTY_H */

