#include <stdarg.h>
#include <main.h>

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
}
}