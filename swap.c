#include "monty.h"

/**
 * swap - swaps the top two elemets of stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;
	int tmp;

	if (s == NULL || s->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	while (s->next != NULL)
	{
		prev = s;
		s = s->next;
	}
	tmp = s->n;
	s->n = prev->n;
	prev->n = tmp;
}
