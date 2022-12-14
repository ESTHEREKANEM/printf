#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * myIdentifier - prints special characters
 * @next: character after the %
 * @args: argument for the indentifier
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int myIdentifier(char next, va_list args)
{
	int j;

	identifier_Struct functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (j = 0; functs[j].indentifier != NULL; j++)
	{
		if (functs[j].indentifier[0] == next)
			return (functs[j].printer(args));
	}
	return (0);
}

/**
 * _printf - mimic printf from stdio
 * Description: produces output according to a format
 * write output to stdout, the standard output stream
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int detectedIdentifier = 0, inputCount = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			inputCount++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			inputCount++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		detectedIdentifier = myIdentifier(format[i + 1], args);
		if (detectedIdentifier == -1 || detectedIdentifier != 0)
			i++;
		if (detectedIdentifier > 0)
			inputCount += detectedIdentifier;

		if (detectedIdentifier == 0)
		{
			_putchar('%');
			inputCount++;
		}
	}
	va_end(args);
	return (inputCount);
}
