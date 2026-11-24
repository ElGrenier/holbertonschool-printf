#include <stdarg.h>
#include "main.h"

/**
 * print_number - dispatch and print numbers
 * @args: The number to be printed
 * Return: Nothing
 */
void print_number(va_list args, int *compteur_ptr)
{
	long number = va_arg(args, int);
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	if (number >= 10)
	{
		print_number(number / 10, *compteur_ptr);
	}
	_putchar(number % 10 + '0');
	*compteur_ptr += 1;

}

/**
 * print_char - print a char
 * @args: The char to be printed
 * Return: Nothing
 */
void print_char(va_list args, int *compteur_ptr)
{
	_putchar(va_arg(args, int));
	*compteur_ptr += 1;
}

/**
 * print_string - decompose a string and print it character by character
 * @args: The string to be printed
 * Return: Nothing
 */
void print_string(va_list args, int *compteur_ptr)
{
	/* Initialize string to be iterated on*/

	char *string;
	for (string = va_arg(args, char *); *string != '\0'; string++)
	{
	_putchar(*string);
	*compteur_ptr += 1;
	}
}

/**
 * select - select the correct way to put the character(s)
 * @args: The aditional arguments of _printf
 * @selector: the character after the inital %
 * Return: Nothing
 */
void select(va_list args, char selector, int *compteur_ptr)
{
	int i = 0;

	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'%', print_char},
		{0, NULL}
	};

	while (formats[i].specifier != 0)
    {
        if (formats[i].specifier == selector)
            formats[i].function(args, compteur_ptr);
        i++;
    }
}