#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
  * _printf - Entry Point
  *
  * Summary: This function prints to stdout
  *
  * @format: Format String
  *
  * @...: Variable Arguments
  *
  * Return: (char_count) int
  */

int _printf(const char *format, ...)
{
	int char_count = 0, fmt_status;
	va_list ap;


	if (format == NULL)
	{
		write(2, "Cannot print null\n", 19);
		return (0);
	}
	fmt_status = parse_format(format);

	if (fmt_status == 1)
	{
		va_start(ap, format);
		while (*format)
		{
			if (*format == '%')
				char_count += p_func(ap, *++format);
			else
				char_count += write(1, format, 1);

			++format;
		}
		va_end(ap);
	}
	else
		write(1, "Invalid format specifier\n", 26);
	return (char_count);
}

/**
  * p_func - Auxilliary Function
  *
  * Description: It calls other print functions based on the specifier
  *
  * @ap: Argument Pointer
  *
  * @specifier: Format Specifier Character
  *
  * Return: (char_count) int - Number of chars printed
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
		case 'i':
			char_count += print_decimal(ap);
			break;
		case '%':
			char_count += write(1, "%", 1);
			break;
		case 'r':
			char_count += print_rev(ap);
			break;
		case 'R':
			char_count += rot13(ap);
			break;
		case 'b':
			char_count += print_binary(ap);
			break;
	}
	va_end(ap);
	return (char_count);
}
