#include "monty.h"

/**
 * free_stack - frees stack memory
 * @stack: the stack header
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp1 = *stack, *tmp2 = *stack;

	while (tmp2 != NULL)
	{
		tmp1 = tmp2;
		tmp2 = tmp1->next;
		free(tmp1);
	}
}
