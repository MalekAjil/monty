#include "monty.h"
#include <stdio.h>

/**
 * ins_push - pushs an integer to stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void ins_push(stack_t **stack, unsigned int line_number)
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
	line_number++;
}

/**
 * ins_pop - pops the top integer from stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: the top integer of the stack, -1 if empty
 */
void ins_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;

	if (s == NULL)
		return;
	while (s->next != NULL)
	{
		prev = s;
		s = s->next;
	}
	line_number = s->n;
	printf("%d\n", s->n);
	free(s);
	if (prev != NULL)
		prev->next = NULL;
}

/**
 * ins_pall - prints all members of the stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void ins_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack, *prev = NULL;

	if (s == NULL)
		return;
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
	line_number++;
}

/**
 * ins_pint - prints the top integer of the stack
 * @stack: the stack header
 * @line_number: the number of line of the instruction
 * Retuen: void
 */
void ins_pint(stack_t **stack, unsigned int line_number)
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
