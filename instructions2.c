#include "monty.h"

/**
 * ins_swap - swaps the top two elemets of stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void ins_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;
	int tmp;

	if (s == NULL || s->next == NULL)
		return;
	while (s->next != NULL)
	{
		prev = s;
		s = s->next;
	}
	tmp = s->n;
	s->n = prev->n;
	prev->n = tmp;
}

/**
 * ins_add - adds the top two elemets of stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: the top integer of the stack, -1 if empty
 */
void ins_add(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;

	if (s == NULL || s->next == NULL)
		return;
	while (s->next != NULL)
	{
		prev = s;
		s = s->next;
	}
	prev->n += s->n;
	free(s);
	prev->next = NULL;
}

/**
 * ins_nop - do nothing
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void ins_nop(stack_t **stack, unsigned int line_number)
{
	return;
}
