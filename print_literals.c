#include <unistd.h>
#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
  * print_char - Auxilliary Function
  *
  * Description: This function handles the %c format specifier
  *
  * @ap: Argument Pointer
  *
  * Return: (Number of chars printed) int
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
  * print_string - Auxilliary Function
  *
  * Description: This function handles the %s formar specifier
  *
  * @ap: Argument Pointer
  *
  * Return: Number of chars printed.
  */

int print_string(va_list ap)
{
	size_t i, len, byte_size;
	int char_count = 0;
	char *str = va_arg(ap, char *);

	len = strlen(str);
	byte_size = (len / MAX_BYTE_SIZE) + 1; /**1 to account for remainders*/

	if (str == NULL)
	{
		write(2, "Error", 6);
		va_end(ap);
		return (-1);
	}

	for (i = 0; i < byte_size; ++i)
	{
		char_count += write(1, str + (i * MAX_BYTE_SIZE),
				MIN(MAX_BYTE_SIZE, len - (i * MAX_BYTE_SIZE)));
	}
	va_end(ap);
	return (char_count);
}
