#include "main.h"

/**
*_printf - print Text.
*@format: The format of the printed string.
*Return: int the number of characters printed
*(excluding the null byte used to end output to strings)
*
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, charCount = 0, printIsDone = 0;
	/*charcount is the number of characters printed that will be return from _printf()*/

	if (format == NULL)
	return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		printIsDone = 0;
		if (format[i] != '%')
		{
			charCount = charCount + _putchar(format[i]);
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':

				printIsDone = printChar(args);
				if (printIsDone <= 0)
				return (-1);

				charCount = charCount + printIsDone;
				i++;
				break;
				case 's':
				/*string*/
				break;
				case '%':
				/*%*/
				break;
				default:
				break;
			}
		}
		i++;
	}
	return (charCount);
}

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
