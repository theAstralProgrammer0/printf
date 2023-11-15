#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX_BYTE_SIZE 30

int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list);
int p_func(va_list, char);
int parse_format(const char *);
int rot13(va_list);
int print_rev(va_list);

void *alloc(size_t);
char *int_to_string(long);
int str_write(char *);
int print_decimal(va_list);


#endif
