#include "main.h"

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

	while (format[indice] != '\0')
	{
		if (format[indice] == '%')
		{
			/* Partie du binome : gestion des conversions */
		}
		else
		{
			if (_putchar(format[indice]) == -1)
				return (-1);
			compteur++;
		}
		indice++;
	}
	return (compteur);
}
