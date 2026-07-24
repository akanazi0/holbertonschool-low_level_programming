#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 *
 * @s1: first string to concatenate
 * @s2: second string to concatenate
 *
 * Return: pointer to newly allocated space containing s1 followed by s2,
 *         or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i;
	int j;
	char *arr;
	int len = 0;
	int len1 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len] != '\0')
		len++;

	while (s2[len1] != '\0')
		len1++;

	arr = malloc(sizeof(char) * (len + len1 + 1));
	if (arr == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		arr[i] = s1[i];

	for (j = 0; s2[j] != '\0'; j++)
	{
		arr[i] = s2[j];
		i++;
	}
	arr[i] = '\0';

	return (arr);
}
