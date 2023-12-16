#include "monty.h"
#include <string.h>

/**
 * str_to_words - split the string into words
 * @str: the string
 * Return: the words array
 */
char **str_to_words(char *str)
{
	char **words = NULL;
	char *str1 = str;
	int i = 0, c = 0, flag = 1;

	if (str == NULL)
		return (NULL);
	while (str1[i])
	{
		printf("str: %c | c: %d\n", str[i], c);
		if ((str[i] != ' ' && str[i] != '\n') && flag == 1)
		{
			c++;
			flag = 0;
		}
		if (str[i + 1] && (str[i + 1] == ' ' || str[i + 1] == '\n'))
			flag = 1;
		i++;
	}
	printf("count: %d", c);
	if (c > 0)
	{
		words = malloc(sizeof(char *) * (c));
		if (words == NULL)
			return (NULL);
		for (i = 0, str1 = str; ; i++, str1 = NULL)
		{
			words[i] = strtok(str1, " \n");
			if (words[i] == NULL)
				break;
		}
	}
	return (words);
}
