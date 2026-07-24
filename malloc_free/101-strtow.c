#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: string to evaluate
 *
 * Return: number of words
 */
static int count_words(char *str)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

/**
 * free_matrix - frees a 2D array of strings
 * @matrix: array to free
 * @n: number of allocated elements
 */
static void free_matrix(char **matrix, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
	char **matrix;
	int i = 0, k = 0, len, words, start, end;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_words(str);
	if (words == 0)
		return (NULL);

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			start = i;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			end = i;
			matrix[k] = malloc(sizeof(char) * (end - start + 1));
			if (matrix[k] == NULL)
			{
				free_matrix(matrix, k);
				return (NULL);
			}
			for (len = 0; start < end; start++, len++)
				matrix[k][len] = str[start];
			matrix[k][len] = '\0';
			k++;
		}
		else
			i++;
	}
	matrix[k] = NULL;
	return (matrix);
}
