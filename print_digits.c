#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

int print_numbers(long int big_num)
{
	int count = 0;
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
	return (count);
}

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

	count += print_numbers(big_num);
	return (count);
}

int print_unsigned(va_list ap)
{
	int count = 0;
	int num = va_arg(ap, unsigned int);
	long big_num = (long) num;

	if (big_num < 0)
		big_num = (UINT_MAX - labs(big_num)) + 1;

	count += print_numbers(big_num);
	return (count);
}


int print_octal(va_list ap)
{
	int i;
	unsigned int count = 0, length = 1, num = va_arg(ap, unsigned int);
	char *num_string, *buffer;
	long tmp = num;

	if (num == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	while (num)
	{
		num /= 8;
		length++;
	}

	buffer = (char *) alloc(length * sizeof(char));
	buffer[length - 1] = '\0';
	num_string = print_oct_helper(tmp, buffer);
	--num_string;

	for (i = length - 2; i >= 0; --i)
		count += write(1, &num_string[i], 1);

	free(buffer);
	return (count);
}


int print_hexa(va_list ap)
{
	int i, j, k;
	unsigned int count = 0, length = 1, num = va_arg(ap, unsigned int);
	char *hex_string, *syms = "0123456789abcdef";
	long tmp = num;

	if (num == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}

	while (num)
	{
		num /= 16;
		length++;
	}

	hex_string = (char *) alloc(length * sizeof(char));

	for (j = length - 2; j >= 0; --j)
	{
		for (i = 0; i < 16; ++i)
		{
			if (i == tmp % 16)
			{
				hex_string[j] = syms[i];
				tmp /= 16;
				break;
			}
		}
	}

	hex_string[length - 1] = '\0';
	
	for (k = 0; k < length - 1; ++k)
		count += write(1, &hex_string[k], 1);

	free(hex_string);
	return (count);
}
