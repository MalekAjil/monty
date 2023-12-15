#include "monty.h"

/**
 * push - pushs an integer to stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL, *new = NULL;

	while (s != NULL)
	{
		prev = s;
		s = s->next;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc faild\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->next = NULL;
	new->prev = prev;
	if (prev != NULL)
		prev->next = new;
}
