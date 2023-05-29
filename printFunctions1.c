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
*printChar - print character.
*@args: va_list
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*
*/

int printChar(va_list args, __attribute__((unused)) int flags,
__attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size)
{
	char c;

	c = (char) va_arg(args, int);
	write(1, &c, 1);

	return (1);
}


/**
*printString - print string.
*@args: va_list
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*
*/
int printString(va_list args, __attribute__((unused)) int flags,
__attribute__((unused)) int width, __attribute__((unused)) int precision,
__attribute__((unused)) int size)
{
	char *str;
	int printedCharCount = 0, i = 0, isPrinted = 0;

	str = va_arg(args, char *);

	if (str == NULL)
	return (-1);

	while (str[i] != '\0')
	{
		isPrinted = write(1, &str[i], 1);
		if (isPrinted <= 0)
		return (-1);

		printedCharCount++;
		i++;

	}

	return (printedCharCount);
}


/**
*printPercent - print %.
*@args: va_list
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*
*/
int printPercent(__attribute__((unused)) va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size)
{
	int printed;
	char c = '%';

	printed = write(1, &c, 1);
	return (printed);
}



/**
*printBinary - print Binary numbers
*@args: va_list
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*
*/
int printBinary(va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size)
{
	int number, i = 0, j, printedBytes = 0, isPrinted = 0;
	int binaryNum[32];

	number = va_arg(args, int);

	if (number < 0)
	return (-1);

	if (number == 0)
	{
		_putchar(0 + 48);
		return (1);
	}

	while (number > 0)
	{
		binaryNum[i] = number % 2;

		number = number / 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		isPrinted = _putchar(binaryNum[j] + 48);

		if (isPrinted <= 0)
		return (-1);

		printedBytes++;
		isPrinted = 0;
	}
	return (printedBytes);
}
