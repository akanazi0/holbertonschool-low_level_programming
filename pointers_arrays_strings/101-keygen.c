#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
	int sum = 2772;
	int rand_char;

	srand(time(NULL));

	while (sum > 126)
	{
		rand_char = (rand() % 93) + 33;
		putchar(rand_char);
		sum -= rand_char;
	}

	putchar(sum);

	return (0);
}
