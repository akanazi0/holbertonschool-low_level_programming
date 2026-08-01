#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a character
 * @args: list of arguments
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an integer
 * @args: list of arguments
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: list of arguments
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: list of arguments
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints arguments of different types
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
	int i = 0, j;
	char *separator = "";
	char *types = "cifs";
	va_list args;
	void (*printers[])(va_list) = {
		print_char, print_int, print_float, print_string
	};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (types[j] != '\0')
		{
			if (format[i] == types[j])
			{
				printf("%s", separator);
				printers[j](args);
				separator = ", ";
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
