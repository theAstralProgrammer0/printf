#include <unistd.h>
#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	va_end(ap);
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
	byte_size = (len / MAX_BYTE_SIZE) + 1; /**plus 1 to account for
						 remainders*/

	if (str == NULL)
	{
		write(2, "Error", 6);
		va_end(ap);
		return (0);
	}

	for (i = 0; i < byte_size; ++i)
	{
		char_count += write(1, str + (i * MAX_BYTE_SIZE),
				MIN(MAX_BYTE_SIZE, len - (i * MAX_BYTE_SIZE)));
	}
	va_end(ap);
	return (char_count);
}

int print_decimal(va_list ap)
{
	int count = 0;
	int num = va_arg(ap, int);
	char *number_string;
	
	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = ABS(num);
	}

	number_string = int_to_string(num);
	count += str_write(number_string);
	free(number_string);
	va_end(ap);
	return (count);
}
