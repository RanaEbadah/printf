
#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define BUFFER_SIZE 1024

int _putchar(char c);


/*print functions*/
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
__attribute__((unused)) int precision, __attribute__((unused)) int size);

int printString(va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size);


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
__attribute__((unused)) int precision, __attribute__((unused)) int size);


/**
*printInteger - print integer.
*@args: va_list
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*
*/
int printInteger(va_list args, __attribute__((unused)) int flags,
__attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size);

long int assign(long int Long_Num, int size);

int printBinary(va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size);


int printInt(va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size);

/**/

int PrintBySpecifier(const char *fmt, int LastFormatIndex, va_list args,
__attribute__((unused)) int flags, __attribute__((unused)) int width,
__attribute__((unused)) int precision, __attribute__((unused)) int size);

int printBuffer(char buffer[], int currentIndex);
int _printf(const char *format, ...);





#endif /* MAIN_H */
