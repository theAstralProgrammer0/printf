#include "main.h"

/**
 * rot13 - prints the rotated position of a string
 * @ap: String to rotate
 * Description: Rotates each character of a string to
 * the next thirteenth position in the alphabet.
 * Return: char printed to stdout.
 */
int rot13(va_list ap)
{	char *str = NULL;
	char c;
	int count = 0;

	str = va_arg(ap, char *);
	while (*str)
	{
		if ((*str >= 65 && *str <= 77) || (*str >= 97 && *str <= 109))
		{
			c = *str + 13;
			count += write(1, &c, 1);
		}
		else if ((*str >= 78 && *str <= 90) || (*str >= 110 && *str <= 122))
		{
			c = *str - 13;
			count += write(1, &c, 1);
		}
		else
		{
			c = *str;
			count += write(1, &c, 1);
		}
		++str;
	}
	return (count);
}
