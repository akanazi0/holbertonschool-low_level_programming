#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings up to n bytes of s2.
 *
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes from s2 to concatenate
 *
 * Return: pointer to allocated space containing s1 followed by n bytes of s2,
 *         or NULL if memory allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	unsigned int j;
	unsigned int len = 0;
	unsigned int len1 = 0;
	unsigned int taken = n;
	char *arr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len] != '\0')
		len++;

	while (s2[len1] != '\0')
		len1++;

	if (taken >= len1)
		taken = len1;

	arr = malloc(sizeof(char) * (len + taken + 1));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		arr[i] = s1[i];

	for (j = 0; j < taken; j++)
	{
		arr[i] = s2[j];
		i++;
	}
	arr[i] = '\0';

	return (arr);
}
