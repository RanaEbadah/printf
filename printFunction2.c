#include "main.h"
/*PRINT DECIMAL & INTEGER NUMBERS */

/**
*printInteger - print integer numbers
*@args: va_list
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: int 1 in success 0 in fail
*/
int printInteger(va_list args,__attribute__((unused)) int flags,
 __attribute__((unused)) int width,
__attribute__((unused)) int precision, int size, char buff[])
{
int i = BUFFER_SIZE - 2;      /* Max condition */
__attribute__((unused)) int Negative_Num = 0;
long int Long_Num = va_arg(args, long int);
unsigned long int uns_long_Num; 

Long_Num = assign(Long_Num, size);

if (Long_Num == 0)
{ 
    buff[i--] = '0';
}
buff[BUFFER_SIZE - 1] = '\0';
uns_long_Num = (unsigned long int)Long_Num;

if (Long_Num < 0)
{
    uns_long_Num = (unsigned long int)((-1) * Long_Num);
    Negative_Num = 1;
}

while (uns_long_Num > 0)
{
    buff[--i] = (uns_long_Num % 10) + '0';
    uns_long_Num /= 10;
}
i++;

return (write(1, &buff, 1));

}


/* ASSIGNED A VLAUE NUMBER ACCORDING TO THE SPECIFIED SIZE */

/** 
 *assign - push number to specified size
 *@Long_Num: number to be pushed
 *@size: number indicates the type of pushed number
 *Return: pushed number value 
 */

long int assign(long int Long_Num, int size)
{
if (size == sizeof(long int))
return (Long_Num);

else if (size == sizeof(int))
return ((short)Long_Num);

return ((int)Long_Num);

}
