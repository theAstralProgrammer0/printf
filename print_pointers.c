#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int print_pointers(va_list ap)
{
	size_t i, start, end, count = 0;
	uintptr_t addr_str;
	void *addr = va_arg(ap, void *);
	char temp, buffer[15];

	addr_str = (uintptr_t)addr;

	buffer[0] = '0';
	buffer[1] = 'x';

	for (i = 2; i < 15 && addr_str != 0; ++i)
	{
		int digit = addr_str % 16;
		buffer[i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		addr_str /= 16;
	}

	start = 2;
	end = i - 1;

	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		++start;
		--end;
	}
	buffer[i] = '\0';

	for (i = 0; i < 14; ++i)
		count += write(1, buffer + i, 1);

	return (count);
}
