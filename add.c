#include "monty.h"

/**
 * add - adds the top two elemets of stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: the top integer of the stack, -1 if empty
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;

	 if (s == NULL || s->next == NULL)
        {
                dprintf(2, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
	while (s->next != NULL)
	{
		prev = s;
		s = s->next;
	}
	prev->n += s->n;
	free(s);
	prev->next = NULL;
}
