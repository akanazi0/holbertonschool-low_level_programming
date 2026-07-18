#include "main.h"

/**
 * puts_half - Prints half of a string, followed by a new line
 * @str: The string to be processed
 *
 * Return: void
 */
void puts_half(char *str)
{
	int length = 0;
	int start;
	int i;

	while (str[length] != '\0')
	{
		length++;
	}

	start = (length + 1) / 2;

	for (i = start; i < length; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
