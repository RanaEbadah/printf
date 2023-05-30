#include "main.h"


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
*printInt - print integar
*@args: va_list
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*
*/
int printInt(va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size)
{
	char numBuffer[20];
	int i, number, printedNumbers = 0;

	number = va_arg(args, int);

	if (number < 0)
	{
		_putchar('-');
		printedNumbers++;
		number = (number * -1);
	}

	if (number == 0)
	{
		return (_putchar('0'));
	}

	for (i = 0; number > 0; i++)
	{
		numBuffer[i] = number % 10 + '0';
		number = number / 10;
	}

	while (i > 0)
	{
		printedNumbers = printedNumbers + write(1, &numBuffer[--i], 1);
	}
	return (printedNumbers);

