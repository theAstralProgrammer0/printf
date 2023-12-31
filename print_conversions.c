#include "main.h"
#include <stdlib.h>

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

/**
 * print_rev - print a string in reverse
 * @ap: variadic argument
 *
 * Return: Number of char printed to stdout
 */
int print_rev(va_list ap)
{
	int len, i, count = 0;
	char *str = va_arg(ap, char *);

	len = strlen(str);

	if (len == 0)
		return (0);
	for (i = len - 1; i >= 0; i--)
		count += write(1, &str[i], 1);
	return (count);
}

/**
 * print_binary - Auxilliary Function
 *
 * Description: This function handles the binary specifier %b which converts
 * an uncsigned int into binary
 *
 * @ap: Argument Pointer
 *
 * Return: (count) int
 */

int print_binary(va_list ap)
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
    num /= 2;
    length++;
  }
  buffer = (char *) alloc(length * sizeof(char));
  buffer[length - 1] = '\0';

  num_string = print_bin_helper(tmp, buffer);
  --num_string;
  
  for (i = length - 2; i >= 0; --i)
    count += write(1, &num_string[i], 1);
  
  free(buffer);
  return (count);
}

int print_hexa_upper(va_list ap)
{
        int i, j;
        unsigned int k, count = 0, length = 1, num = va_arg(ap, unsigned int);
        char *hex_string, *syms = "0123456789ABCDEF";
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

