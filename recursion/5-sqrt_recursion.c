#include "main.h"

/**
 * _sqrt_helper - Finds the natural square root of a number recursively.
 * @n: The number to find the square root of.
 * @i: The current guess/iterator.
 *
 * Return: The natural square root, or -1 if not found.
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);

	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root, or -1 if n does not have a natural sqrt.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_sqrt_helper(n, 0));
}
