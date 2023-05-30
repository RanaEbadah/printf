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

	int flags = 0, precession = 0, width = 0, size = 0;
	int i = 0, buffCurrentIndex = 0, printed = 0, printedChars = 0;

	char buffer[BUFFER_SIZE];

	if (format == NULL)
	return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			/*it will be normal text to print*/
			buffer[buffCurrentIndex] = format[i];
			buffCurrentIndex++;

			if (buffCurrentIndex == BUFFER_SIZE - 1)
			{
				/*go to print the buffer content because it
				is full and start again to fill it*/
				if ((printBuffer(buffer, buffCurrentIndex)) <= 0)
				return (-1);

				/*set buffCurrentIndex by zero th start filling the buffer again*/
				buffCurrentIndex = 0;
			}

			printedChars++;

		}
		else
		{
			/*format specifier is coming*/
			if (buffCurrentIndex > 0)
			{
				/*go and print the buffer first before we will handle the specifier*/
				if ((printBuffer(buffer, buffCurrentIndex)) <= 0)
				return (-1);
			}

			/*we will call the speceifier functions here*/
			printed = PrintBySpecifier(format, i + 1, args, flags, width, precession, size);
			if (printed <= 0)
			return (-1);

			printedChars += printed;
			i++;

			/*set buffCurrentIndex by zero th start filling the buffer again*/
			buffCurrentIndex = 0;

		}
		i++;
	}

	if (buffCurrentIndex > 0)
	{
		if ((printBuffer(buffer, buffCurrentIndex)) <= 0)
		return (-1);
		/*we are finished looping so go and print the buffer */
	}

	va_end(args);
	return (printedChars);

}

/**
*printBuffer - print the buffer content.
*@buffer: the buffer that will be print
*@bufferLastIndex: the last index in the buffer
*/
int printBuffer(char buffer[], int bufferLastIndex)
{
	int i;
	if (bufferLastIndex > 0)
	{

		for (i = 0; i < bufferLastIndex; i++)
		{
			write(1, &buffer[i], 1);
		}

		return (1);
	}
	else
	return (-1);
}

/**
*PrintBySpecifier - print .
*@fmt: string
*@LastFormatIndex: int
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*
*/
int PrintBySpecifier(const char *fmt, int LastFormatIndex, va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size)
{
	/*char specifier[] = {'c', 's', '%', 'b', '\0'};
	int (*printFun[]) (va_list, int, int, int, int) = {&printChar, &printString,
	&printPercent, &printBinary, NULL};*/
	char specifier[] = {'c', 's', '%','b','\0', 'd', 'i'};
	int (*printFun[]) (va_list, int, int, int, int, int, int) = {printChar, printString,
	printPercent, printBinary, NULL, printInteger, printInteger};
	int i;

	for (i = 0; specifier[i] != '\0'; i++)
	{
		if (fmt[LastFormatIndex] == specifier[i])
		{
			return (printFun[i](args, flags, width, precision, size));
		}
	}

	return (-1);

}
