#include "main.h"

/**
 * _puts - Prints a string followed by a new line to stdout.
 * @str: Pointer to the string (char array) to be printed.
 *
 * Description: Loops through each memory address of the string,
 * printing one character at a time until the Null Terminator ('\0') is found.
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
