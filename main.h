#ifndef MAIN_H
#define MAIN_H

typedef struct format
{
    char specifier;
    int (*function)(va_list, int *);
} format_t;

int _putchar(char c);

int _printf(const char *format, ...);

#endif
