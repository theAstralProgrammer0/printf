#include <string.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>

/**
  * alloc - Auxilliary Function
  *
  * Summary: Allocates memory, frees and returns NULL if failed
  *
  * @size: Size ot be allocated
  *
  * Return: (ptr) Success, (NULL) Failure
  */

void *alloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

/**
  * int_to_string - Auxilliary Function
  *
  * Description: Converts and integer to a number string
  *
  * @num: Integer to be stringified
  *
  * Return: (num_str) char *
  */

char *int_to_string(long num)
{
	long length = 1, tmp;
	char *num_str;
	long i;

	tmp = num;

	while (num)
	{
		length++;
		num /= 10;
	}
	num_str = (char *) alloc(length * sizeof(char));

	for (i = length - 2 ; i >= 0; --i)
	{
		num_str[i] = (tmp % 10) + '0';
		tmp /= 10;
	}
	num_str[length - 1] = '\0';
	return (num_str);
}

/**
  * str_write - Auxilliary Function
  *
  * Summary: This function writes any string to standard output
  *
  * @number_string: String to be written to stdout
  *
  * Return: (count) int - Count of chars written
  */

int str_write(char *number_string)
{
	size_t i, len, byte_size;
	int count = 0;

	if (number_string == NULL)
	{
		write(2, "Error", 6);
		return (-1);
	}
	len = strlen(number_string);
	byte_size = ((len - 1) / MAX_BYTE_SIZE) + 1;

	for (i = 0; i < byte_size; ++i)
	{
		count += write(1, number_string + (i * MAX_BYTE_SIZE),
				MIN(MAX_BYTE_SIZE, len - (i * MAX_BYTE_SIZE)));
	}
	return (count);
}


char *print_bin_helper(unsigned int num, char *buffer)
{
        if (num == 0)
                return (buffer);

        *buffer = (num % 2) + '0';
        num /= 2;
        ++buffer;
        print_bin_helper(num, buffer);

        return (buffer);
}
