#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers containing values from min to max.
 *
 * @min: minimum value to start from
 * @max: maximum value to end at
 *
 * Return: pointer to the created array, or NULL if min > max or malloc fails
 */
int *array_range(int min, int max)
{
	int i;
	int size;
	int *arr;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}
