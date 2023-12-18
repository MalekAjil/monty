#include "monty.h"

/**
 * pint - prints the top integer of the stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	if (s == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (s->next != NULL)
	{
		s = s->next;
	}
	printf("%d\n", s->n);
}
