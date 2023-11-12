#include "main.h"

/**
 * parse_format - parse format string
 * @fmt - Format string to parse
 * Description: Determines if the format string 
 * contains valid format specifiers.
 * Return: 1 (valid) or 0 (invalid).
 */
int parse_format(const char *fmt)
{
	int i = 0, ret_val, len = strlen(fmt) - 1;

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
			if (fmt[i + 1] != 'c' && fmt[i + 1] != 's' && fmt[i + 1]
					!= '%')
			{
				ret_val = 0;
				break;
			}
			if (fmt[i + 1] == '%') /* % was escaped */
			{
				/* Returns (0) when last char is % */
				if ((i + 2) == len && fmt[i + 2] == '%')
				{
					ret_val = 0;
					break;
				}
				/*Fast forward check to determine next-2 chars*/
				if ((i + 2) < len)
				{
					ret_val = (handle_percent(fmt[i + 2], fmt[i
								+ 3]));
					if (ret_val == 0)
						break;
				}
			}
			i += 2; /* skip determined fmt specifier */
		}
		else
		{
			ret_val = 1;
			i++;
		}
	}
	return (ret_val);
}

/**
 * handle_percent - fast forward check
 * @nxt2: Third char of *fmt
 * @nxt3: Fourth char of *fmt
 * Description: Fast forward check the next
 * two chars of %.
 * Return: 1 (valid) or 0 (invalid)
 */
int handle_percent(char nxt2, char nxt3)
{
	if (nxt2 == '%')
		if (nxt3 != 'c' && nxt3 != 's' && nxt3 != '%')
			return (0);
	return (1);
}
