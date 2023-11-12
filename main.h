#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int _printf(const char *format, ...);
int parse_format(const char *);
int handle_percent(char, char);
int p_func(va_list, char);
int print_char(va_list);
int print_string(va_list);

#endif
