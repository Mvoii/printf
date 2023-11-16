#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int puts_char(int c);
int puts_str(char *str);
int print_format(char specifier, va_list list_args);
/*char* int_to_string(int num);*/
int puts_integer(int value);
int puts_digits(long n, int base);
int puts_digit_caps(long n, int base);

#endif /*MAIN_H*/
