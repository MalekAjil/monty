#include "monty.h"

/**
 * pop - pops the top integer from stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: the top integer of the stack, -1 if empty
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;

	if (s == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (s->next != NULL)
	{
		prev = s;
		s = s->next;
	}
	line_number++;
	line_number = s->n;
	printf("%d\n", s->n);
	free(s);
	if (prev != NULL)
		prev->next = NULL;
}
