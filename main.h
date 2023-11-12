#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list);
int p_func(va_list, char);
void print_error(char *);

#endif
