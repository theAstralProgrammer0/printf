#include <unistd.h>
#include "main.h"

/**
  * print_char - prints char
  * @ap: Variadic arguments
  *
  * Return: Number of chars printed.
  */
int print_char(va_list ap)
{
	int ch = va_arg(ap, int);

	if (ch == 0)
		return (write(1, "", 1));
	return (write(1, &ch, 1));
}

/**
  * print_string - prints a string
  * @ap: Variadic arguments
  *
  * Return: Number of chars printed.
  */
int print_string(va_list ap)
{
	int char_count = 0;
	char *str = va_arg(ap, char *);

	if (str == NULL)
		str = "(nil)";
	while (*str)
	{
		char_count += write(1, str, 1);
		++str;
	}
	return (char_count);
}
