#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>


typedef struct format
{
    char specifier;
    int (*function)(va_list);
} format_t;

int _putchar(char c);

int _printf(const char *format, ...);

void select(va_list args, char selector);

#endif
