#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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

	if (!(*format))
		write(1, "User input is needed", 21);

	while (*format)
	{
		if (*format == '%')
			char_count += p_func(ap, *++format);
		else
			char_count += write(1, format, 1);

		++format;
	}

	return (char_count);
}

/**
  * p_func - executes print function
  * @ap: Variadic arguments
  * @specifier: Format type pointer
  *
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
		case '%':
			char_count += write(1, "%", 1);
			break;
	}

	return (char_count);
}
