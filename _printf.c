#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * gerer_conversion - Handles format conversions
 * @args: Variadic arguments
 * @caractere: Conversion specifier
 *
 * Return: Number of characters printed, or -1 on error
 */

int gerer_conversion(va_list args, char caractere)
{
	if (caractere == '\0')
		return (-1);
	return (select(args, caractere));
}

/**
 * _printf - Prints a formatted string
 * @format: The format string
 *
 * Return: Number of characters printed, or -1 on error
 */

int _printf(const char *format, ...)
{
	int indice = 0;
	int compteur = 0;
	int resultat;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[indice] != '\0')
	{
		if (format[indice] == '%')
		{
			resultat = gerer_conversion(args, format[indice + 1]);
			if (resultat == -1)
			{
				va_end(args);
				return (-1);
			}
			compteur += resultat;
			indice++;
		}
		else
		{
			if (_putchar(format[indice]) == -1)
			{
				va_end(args);
				return (-1);
			}
			compteur++;
		}
		indice++;
	}
	va_end(args);
	return (compteur);
}
