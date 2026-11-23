#include <stdarg.h>
#include <main.h>

/**
 * print_digits - dispatch and print numbers
 * @n: The number to print
 * Return: Nothing
 */
void put_digits(long number)
{
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	if (number >= 10)
	{
		print_digits(number / 10);
	}
	_putchar(number % 10 + '0');
}

/**
 * select - select the correct way to put the character(s)
 * @args: The aditional arguments of _printf
 * @selector: the character after the inital %
 * Return: Nothing
 */
void select(va_list args, char selector)
{
char *string;
switch (selector){
case '%':
	_putchar('%');
	break;
case 's':
	/* Initialize string to be iterated on*/
	for (string = va_arg(args, char *); *string != '\0'; string++)
	{
	_putchar(*string);
	}
	break;
case 'c':
	/* print the letter directly*/
	_putchar(va_arg(args, int));
	break;
case 'd':
	/* Falltrough, it also execute case 'i'*/
case 'i':
	print_digits(va_arg(args, int));
	break;
}
}