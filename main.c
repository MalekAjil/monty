#include "monty.h"

int gvar = -1;    /* Definition of global variable */
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
	int top = -1;
	int file;
	stack_t *stack;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open(av[1], O_RDONLY);
	if (file == -1)
	{
		dprintf(2, "Erorr: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, file) != -1)
	{
		l_num++;
		words = str_to_words(line);
		if (words != NULL)
		{
			if (words[1] != NULL)
				gvar = atoi(words[1]);
			(get_ins_func(words[0]))(&stack, l_num);
		}
		free(words);
		line = NULL;
	}
	close(file);
	free(line);
}
