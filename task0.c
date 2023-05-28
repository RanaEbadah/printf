#include "main.h"

/**
*printChar - print character.
*@args: va_list
*Return: int 1 in success 0 in fail
*
*/

int printChar(va_list args)
{
    char c;

    c = (char) va_arg(args, int);
	return (_putchar(c));
}
