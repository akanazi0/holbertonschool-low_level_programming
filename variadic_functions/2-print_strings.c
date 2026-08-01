#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: string to be printed between strings
 * @n: number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *m;
	va_list aq;

	va_start(aq, n);

	for (i = 0; i < n; i++)
	{
		m = va_arg(aq, char *);
		if (m == NULL)
			printf("(nil)");
		else
			printf("%s", m);

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	va_end(aq);
	printf("\n");
}
