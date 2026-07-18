#include "main.h"

/**
 * reverse_buffer - Reverses the character buffer
 * @s: The buffer string to reverse
 *
 * Return: void
 */
void reverse_buffer(char *s)
{
	int i = 0, j = 0;
	char temp;

	while (s[j] != '\0')
		j++;
	j--;

	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

/**
 * infinite_add - Adds two numbers
 * @n1: First number string
 * @n2: Second number string
 * @r: Buffer to store result
 * @size_r: Buffer size
 *
 * Return: Pointer to the result, or 0 if it cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, sum = 0, carry = 0;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;

	if (i + 2 > size_r || j + 2 > size_r)
		return (0);

	i--;
	j--;
	while (i >= 0 || j >= 0 || carry != 0)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		carry = sum / 10;
		if (k >= size_r - 1)
			return (0);

		r[k++] = (sum % 10) + '0';
		i--;
		j--;
	}
	r[k] = '\0';
	reverse_buffer(r);
	return (r);
}
