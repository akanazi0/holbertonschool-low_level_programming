#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers
 * @a: Pointer to the array of integers
 * @n: The number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int left = 0;
	int right = n - 1;
	int temp;

	while (left < right)
	{
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;

		left++;
		right--;
	}
}
