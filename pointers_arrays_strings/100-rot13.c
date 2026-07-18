#include "main.h"

/**
 * rot13 - Encodes a string using rot13
 * @s: The string to be encoded
 *
 * Return: A pointer to the encoded string
 */
char *rot13(char *s)
{
	int i = 0;
	int j;
	char src[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char dest[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (s[i] != '\0')
	{
		for (j = 0; src[j] != '\0'; j++)
		{
			if (s[i] == src[j])
			{
				s[i] = dest[j];
				break;
			}
		}
		i++;
	}

	return (s);
}
