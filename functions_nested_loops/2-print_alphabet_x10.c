#include "main.h"
/**
* print_alphabet_x10 - print alphabet 10 times
*
* Return: void
**/
void print_alphabet_x10(void)
{
char letter;
int i;

letter = 'a';
i = 1;

while (i <= 10)
{
letter = 'a';
while (letter <= 'z')
{
_putchar(letter);
letter++;
}
_putchar('\n');
i++;
}
}
