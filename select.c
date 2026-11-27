#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * recursive_print - print recursively a number
 * @number: The number to be printed
 * Return: Nothing
 */
int recursive_print(long number)
{
	int count = 0;

	if (number < 0)
	{
		_putchar('-');
		count++;
		number = -number;
	}
	if (number >= 10)
	{
		count += recursive_print(number / 10);
	}
	_putchar(number % 10 + '0');
	return (count + 1);
}

/**
 * print_number - call the recursive function
 * @args: The number to be printed
 * Return: Nothing
 */
int print_number(va_list args)
{
	return (recursive_print(va_arg(args, int)));
}

/**
 * print_char - print a char
 * @args: The char to be printed
 * Return: Nothing
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - decompose a string and print it character by character
 * @args: The string to be printed
 * Return: Nothing
 */
int print_string(va_list args)
{
	/* Initialize string to be iterated on*/
	char *string;
	int count = 0;

	string = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";
	for (; *string != '\0'; string++)
	{
		_putchar(*string);
		count++;
	}
	return (count);
}

/**
 * select - select the correct way to put the character(s)
 * @args: The aditional arguments of _printf
 * @selector: The character selector after the %
 * Return: Nothing
 */
int select(va_list args, char selector)
{
	int i = 0;

	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{0, NULL}
	};

	/*If its %%, don't check for the format and directly print a %*/
	if (selector == '%')
		return (_putchar('%'), 1);

	while (formats[i].specifier != 0)
	{
		if (formats[i].specifier == selector)
			return (formats[i].function(args));
		i++;
	}
	return (-1);
}
