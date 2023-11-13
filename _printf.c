#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
  * _printf - prints to stdout
  * @format: Specifies the format to print
  * @...: Variadic arguments
  *
  * Return: Number of chars printed.
  */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list ap;

	va_start(ap, format);

	if (format == NULL)
	{
		write(2, "Cannot print null", 18);
		return (0);
	}

	while (*format)
	{
		if (*format == '%')
			char_count += p_func(ap, *++format);
		else
			char_count += write(1, format, 1);

		++format;
	}
	va_end(ap);
	return (char_count);
}

/**
  * p_func - Auxilliary Function
  * Description: It calls other print functions based on the specifier
  * @ap: Argument Pointer
  * @specifier: Format Specifier Character
  * Return: Number of chars printed
  */
int p_func(va_list ap, char specifier)
{
	int char_count = 0;

	switch (specifier)
	{
		case 'c':
			char_count += print_char(ap);
			break;
		case 's':
			char_count += print_string(ap);
			break;
		case 'd':
			char_count += print_decimal(ap);
			break;
		case '\0':
			write(2, "Invalid Format\n", 16);
			break;
		case '%':
			char_count += write(1, "%", 1);
			break;
		default:
			break;
	}
	va_end(ap);
	return (char_count);
}
