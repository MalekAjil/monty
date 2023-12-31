#include "monty.h"

/**
 * pall - prints all members of the stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;

	while (s != NULL)
	{
		prev = s;
		s = s->next;
	}
	while (prev != NULL)
	{
		printf("%d\n", prev->n);
		prev = prev->prev;
	}
	if (line_number == 0)
		line_number++;
}
