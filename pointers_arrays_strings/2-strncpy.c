#include "main.h"

/**
 * _strncpy - Copies a string up to n bytes
 * @dest: The destination buffer to copy to
 * @src: The source string to be copied
 * @n: The maximum number of bytes to copy
 *
 * Return: A pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
