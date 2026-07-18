#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @s: The string to be encoded
 *
 * Return: A pointer to the encoded string
 */
char *leet(char *s)
{
	int i = 0;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	while (s[i] != '\0')
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = numbers[j];
			}
		}
		i++;
	}

	return (s);
}
