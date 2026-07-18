#include "main.h"
#include <stdio.h>

/**
 * print_hex - Prints the hex representation of 10 bytes
 * @b: Pointer to the buffer
 * @start: Start index of the current line
 * @size: Total size of the buffer
 *
 * Return: void
 */
void print_hex(char *b, int start, int size)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if ((start + i) < size)
			printf("%02x", b[start + i]);
		else
			printf("  ");

		if (i % 2 != 0)
			printf(" ");
	}
}

/**
 * print_ascii - Prints the printable characters of 10 bytes
 * @b: Pointer to the buffer
 * @start: Start index of the current line
 * @size: Total size of the buffer
 *
 * Return: void
 */
void print_ascii(char *b, int start, int size)
{
	int i;
	char c;

	for (i = 0; i < 10; i++)
	{
		if ((start + i) < size)
		{
			c = b[start + i];
			if (c >= 32 && c <= 126)
				printf("%c", c);
			else
				printf(".");
		}
	}
}

/**
 * print_buffer - Prints a buffer size bytes at a time
 * @b: Pointer to the buffer
 * @size: Number of bytes to print
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int start = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	while (start < size)
	{
		printf("%08x: ", start);
		print_hex(b, start, size);
		print_ascii(b, start, size);
		printf("\n");
		start += 10;
	}
}
