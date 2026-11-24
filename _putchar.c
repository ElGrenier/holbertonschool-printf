#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: Number of bytes written, or -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
