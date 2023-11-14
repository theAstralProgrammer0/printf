#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
  * print_decimal - Auxilliary Function
  *
  * Description: This function handles the %d format specifier
  *
  * @ap: Argumnet Pointer
  *
  * Return: (count) int - Number of characters printed
  */

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
	if (num == 0)
		return (write(1, "0", 1));
	number_string = int_to_string(num);
	count += str_write(number_string);
	free(number_string);
	va_end(ap);
	return (count);
}
