#include <stdlib.h>
#include <error.h>
#include "main.h"

/**
  * print_error - prints error
  * @err_msg: Error message
  *
  * Return: Nothing.
  */
void print_error(char *err_msg)
{
	error_at_line(EXIT_FAILURE, 0, __FILE__, __LINE__, "Error: %s", err_msg);
}
