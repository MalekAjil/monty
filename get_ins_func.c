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
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};

	i = 0;
	while (ins[i].opcode != NULL)
	{
		if (!strcmp(ins[i].opcode, s))
			return (ins[i].f);
		i++;
	}
	return (NULL);
}
