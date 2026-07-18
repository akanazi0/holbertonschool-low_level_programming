#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to be modified
 *
 * Return: A pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;
	char seps[] = " \t\n,;.!?\"(){}";

	if (str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] = str[i] - 32;
	}
	i++;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			for (j = 0; seps[j] != '\0'; j++)
			{
				if (str[i - 1] == seps[j])
				{
					str[i] = str[i] - 32;
					break;
				}
			}
		}
		i++;
	}

	return (str);
}
