#include "monty.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments values
 * Return: 0 (success), 1 (failure)
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **words = NULL;
	size_t n = 0;
	int l_num = 0;
	FILE *file;
	stack_t *stack;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		dprintf(2, "Erorr: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &n, file)) != -1)
	{
		l_num++;
		words = str_to_words(line);
		if (words != NULL)
		{
			if (!strcmp(words[0], "push"))
			{
				if (words[1] == NULL)
				{
					dprintf(2, "L%d: usage: push integer\n", l_num);
					exit(EXIT_FAILURE);
				}
				l_num = atoi(words[1]);
			}
			(get_ins_func(words[0]))(&stack, l_num);
			free(words);
		}
	}
	fclose(file);
	free(line);
	return (0);
}
