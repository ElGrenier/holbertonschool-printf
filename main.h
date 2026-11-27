#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/**
 * struct format - Associates a specifier with a function
 * @specifier: Conversion specifier
 * @function: Associated conversion function
 */
typedef struct format
{
	char specifier;
	int (*function)(va_list);
} format_t;

int _putchar(char c);
int _printf(const char *format, ...);
int select(va_list args, char selector);
int recursive_print(long number);
int print_number(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int gerer_conversion(va_list args, char caractere);
#endif
