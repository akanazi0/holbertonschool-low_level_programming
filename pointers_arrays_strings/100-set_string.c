#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: Double pointer to a string (pointer to pointer)
 * @to: Pointer to the target string to point to
 *
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
