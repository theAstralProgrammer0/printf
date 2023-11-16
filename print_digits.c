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
	long big_num = (long) num;
	char *number_string;

	if (big_num < 0)
	{
		write(1, "-", 1);
		count++;
		big_num = labs(big_num);
	}
	if (big_num == 0)
		return (write(1, "0", 1));
	number_string = int_to_string(big_num);
	count += str_write(number_string);
	free(number_string);
	va_end(ap);
	return (count);
}

int print_unsigned(va_list ap)
{
	count += print_digit(ap);
	return (count);
}


int print_octal(va_list ap)
{
	/**code*/

	return (count);
}


int print_octal(va_list ap)
{
	/**code*/

	return (count);
}
