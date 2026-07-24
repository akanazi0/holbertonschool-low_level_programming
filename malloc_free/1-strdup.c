#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *           which contains a copy of the string given as a parameter.
 *
 * @str: string to copy
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL
 *         or memory allocation fails
 */
char *_strdup(char *str)
{
	int i;
	char *arr;
	int len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	arr = malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		arr[i] = str[i];

	return (arr);
}
