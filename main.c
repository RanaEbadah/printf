#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{

    int len1, len2, len3;
    len1 = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    len3 = _printf(" ");

    printf("len1 = %d, len2 = %d, len3 = %d\n", len1, len2, len3);
   
    len1 = _printf("Character:[%c] lets try %c this\n", 'H', 'R');
    len2 = printf("Character:[%c] lets try %c this\n", 'H', 'R');

    printf("len1 = %d, len2 = %d\n", len1, len2);

    len1 = _printf("String:[%s]\n", "I am a string !");
    len2 = printf("String:[%s]\n", "I am a string !");

    printf("len1 = %d, len2 = %d\n", len1, len2);

    len1 = _printf("Percentage:[%%]\n");
    len2 = printf("Percentage:[%%]\n");

    printf("len1 = %d, len2 = %d\n", len1, len2);
    
   
    len1 = _printf("%b\n", 98);
    len2 = _printf("%b\n", 0);
    _printf("%b\n", -1);
    len3 = _printf("%b\n", 9363638);

    printf("len1 = %d, len2 = %d, len3 = %d\n", len1, len2, len3);

    
    
    return (0);
}
