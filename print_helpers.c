#include <string.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void *alloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}


char *int_to_string(int num)
{
	int length = 1, tmp;
	char *num_str;
	int i;

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


int str_write(char *number_string)
{
	size_t i, len, byte_size;
	int count = 0;

	len = strlen(number_string);
	byte_size = ((len - 1) / MAX_BYTE_SIZE) + 1;

	for (i = 0; i < byte_size; ++i)
	{
		count += write(1, number_string + (i * MAX_BYTE_SIZE),
				MIN(MAX_BYTE_SIZE, len - (i * MAX_BYTE_SIZE)));
	}
	return (count);
}
