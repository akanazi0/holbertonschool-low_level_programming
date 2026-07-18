#include "main.h"

/**
 * print_rev - Prints a string, in reverse, followed by a new line.
 * @s: Pointer to the string to be reversed and printed.
 *
 * Description: First counts the length of the string to find the end,
 * then loops backward from the last character to the first, printing each.
 */
void print_rev(char *s)
{
	int length = 0;
	int i;

	while (s[length] != '\0')
	{
		length++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	_putchar('\n');
}
