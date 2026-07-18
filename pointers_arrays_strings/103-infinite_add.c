#include "main.h"

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
	int i = 0, j = 0, k = 0;
	int len1 = 0, len2 = 0;
	int sum = 0, carry = 0;
	char temp;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	if (len1 + 2 > size_r || len2 + 2 > size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;

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

		r[k] = (sum % 10) + '0';
		k++;
		i--;
		j--;
	}
	r[k] = '\0';

	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}
	return (r);
}
