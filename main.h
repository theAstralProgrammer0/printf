#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX_BYTE_SIZE 30

int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list);
int p_func(va_list, char);
void print_error(char *);
int parse_format(const char *);

void *alloc(size_t);
char *int_to_string(int);
int str_write(char *);
int print_decimal(va_list);


#endif
