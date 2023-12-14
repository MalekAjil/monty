#include "monty.h"

/**
 * get_ins_func - selects the correct function to perform the instruction
 * @s: is the opcode as argument to program
 *
 * Return: a pionter to correct function
 */
void (*get_ins_func(char *s))(stack_t **, unsigned int)
{
	int i;
	instruction_t ins[] = {
		{"push", ins_push},
		{"pop", ins_pop},
		{"pall", ins_pall},
		{"pint", ins_pint},
		{"add", ins_add},
		{"swap", ins_swap},
		{"nop", ins_nop},
		{NULL, NULL}
	};

	i = 0;
	while (ins[i].opcode != NULL)
	{
		if (ins[i].opcode == s)
			return (ins[i].f);
		i++;
	}
	return (NULL);
}
