#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program.
 *
 * @ac: argument count
 * @av: argument vector (array of strings)
 *
 * Return: pointer to new string, or NULL if ac == 0, av == NULL, or fails
 */
char *argstostr(int ac, char **av)
{
	int i;
	int j;
	int k = 0;
	int total_len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length needed including '\n' for each argument */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_len++;
		total_len++; /* Account for '\n' */
	}

	/* Allocate memory for total characters + '\0' */
	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
		return (NULL);

	/* Copy arguments into newly allocated space */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';

	return (str);
}
