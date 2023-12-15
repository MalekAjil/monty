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
		return;
	while (s->next != NULL)
	{
		s = s->next;
	}
	printf("%d\n", s->n);
	line_number++;
}
