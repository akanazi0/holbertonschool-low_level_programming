#include "main.h"
/**
* _islower - check if the letter is lower or not
* @c: character to check
*
* Return: 1 if lowercase - 0 if not
*
**/
int _islower(int c)
{
if (c >= 'a' && c <= 'z')
{
return (1);
}
else
{
return (0);
}
}
