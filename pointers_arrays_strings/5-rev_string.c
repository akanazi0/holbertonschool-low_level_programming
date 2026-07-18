#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: The string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0;
	int left = 0;
	int right;
	char temp;

	while (s[length] != '\0')
	{
		length++;
	}

	right = length - 1;

	while (left < right)
	{
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;

		left++;
		right--;
	}
}
