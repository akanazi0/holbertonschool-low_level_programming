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
 * _strlen - returns length of string.
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
 * is_digit - checks if string contains only digits.
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
 * multiply - multiplies two digit strings and prints result.
 * @s1: first number string
 * @s2: second number string
 */
void multiply(char *s1, char *s2)
{
	int len1, len2, len_res, i, j, digit1, digit2, carry, *res, start = 0;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len_res = len1 + len2;

	res = malloc(sizeof(int) * len_res);
	if (res == NULL)
		error_exit();

	for (i = 0; i < len_res; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += res[i + j + 1] + (digit1 * digit2);
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			res[i + j + 1] += carry;
	}

	while (start < len_res - 1 && res[start] == 0)
		start++;

	for (i = start; i < len_res; i++)
		_putchar(res[i] + '0');
	_putchar('\n');

	free(res);
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
	int i, is_zero1 = 1, is_zero2 = 1;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		error_exit();

	s1 = argv[1];
	s2 = argv[2];

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != '0')
		{
			is_zero1 = 0;
			break;
		}
	}

	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s2[i] != '0')
		{
			is_zero2 = 0;
			break;
		}
	}

	if (is_zero1 || is_zero2)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	multiply(s1, s2);

	return (0);
}
