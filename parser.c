#include "main.h"

/**
 * parse_format - parse format string
 * @fmt: Format string to parse
 * Description: Determines if the format string
 * contains valid format specifiers.
 * Return: 1 (valid) or 0 (invalid).
 */
int parse_format(const char *fmt)
{	int i = 0, ret_val = 1, len = strlen(fmt) - 1;

	while (i <= len)
	{
		if (fmt[i] == '%')
		{
			if (i + 1 > len) /* fmt[i] is the last char of *fmt */
			{
				ret_val = 0;
				break;
			}
			/* char fmt[i] does not denote allowed specifier */
			if (fmt[i + 1] != 'c' && fmt[i + 1] != 's' && fmt[i +
					1] != '%' && fmt[i + 1] != 'd' && fmt[i
					+ 1] != 'i' && fmt[i + 1] != 'r' && fmt
					[i + 1] != 'R')
			{
				ret_val = 0;
				break;
			}
			i += 2; /* skip determined fmt specifier */
		}
		else
			i++;
	}
	return (ret_val);
}
