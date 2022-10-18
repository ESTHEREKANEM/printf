#include <stdarg.h>
#include "main.h"
/**
 * _printf - This is the entry point for a printf function clone.
 *
 * @format: this is the first parameter passed to the function
 * which mostlikely is a string
 *
 * @...: this are other functions that would be saved as args.
 *
 * Return: the number of character printed excluding the end output to string.
*/

int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; i != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c' || format[i] == 's')
			{
				char c = (char) va_arg(args, int);
				_putchar(c);
			}
		}
		_putchar(format[i]);
	}

	return (i);
}
