#include "main.h"
#include <stdlib.h>

/**
 * error_exit - prints Error and exits with status 98.
 */
void error_exit(void)
{
	char *err = "Error\n";
	int i;

	for (i = 0; err[i] != '\0'; i++)
		_putchar(err[i]);

	exit(98);
}

/**
 * _strlen - returns the length of a string.
 * @s: string to measure
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * is_digit - checks if a string contains only digits.
 * @s: string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * main - multiplies two positive numbers.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exit 98 on failure
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len_result, i, j, digit1, digit2, carry, *result, start = 0;

	if (argc != 3)
		error_exit();

	s1 = argv[1];
	s2 = argv[2];

	if (!is_digit(s1) || !is_digit(s2))
		error_exit();

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len_result = len1 + len2;

	result = malloc(sizeof(int) * len_result);
	if (result == NULL)
		error_exit();

	for (i = 0; i < len_result; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}

	while (start < len_result - 1 && result[start] == 0)
		start++;

	for (i = start; i < len_result; i++)
		_putchar(result[i] + '0');
	_putchar('\n');

	free(result);
	return (0);
}
