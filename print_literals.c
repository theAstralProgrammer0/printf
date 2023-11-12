#include <unistd.h>
#include "main.h"
#include <string.h>

#define MAX_BYTE_SIZE 30

/**
  * print_char - prints char
  * @ap: Variadic arguments
  *
  * Return: Number of chars printed.
  */
int print_char(va_list ap)
{
	int ch = va_arg(ap, int);

	switch (ch)
	{
		case 0:
			return (write(1, "", 1));
		case '\n':
			return (write(1, "\n", 1));
		case '\r':
			return (write(1, "\r", 1));
		case '\t':
			return (write(1, "\t", 1));
		case '\a':
			return (write(1, "\a", 1));
		case '\b':
			return (write(1, "\b", 1));
		case '\v':
			return (write(1, "\v", 1));
		case '\f':
			return (write(1, "\f", 1));
		default:
			break;
	}
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
	size_t i, len, byte_size;
	int char_count = 0;
	char *str = va_arg(ap, char *);

	len = strlen(str);
	byte_size = (len / MAX_BYTE_SIZE) + 1;

	if (str == NULL)
	{
		write(2, "Error", 6);
		return (0);
	}

	for (i = 0; i < byte_size; ++i)
	{
		char_count += write(1, str + (i * MAX_BYTE_SIZE),
				MIN(MAX_BYTE_SIZE, len - (i * MAX_BYTE_SIZE)));
	}
	return (char_count);
}
