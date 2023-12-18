#include "monty.h"

/**
 * nop - do nothing
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && line_number)
		return;
}
