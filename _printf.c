#include "main.h"

/**
 * print_format - writes data formatted against some parameters
 *
 * @list_args: the arguemnts list
 *
 * @specifier: identifies the data type
 *
 * Returns: count of bytes printed
 */
int print_format(char specifier, va_list list_args)
{
	int count = 0;

	/*handles char*/
	if (specifier == 'c')
		count += puts_char(va_arg(list_args, int));
	else if (specifier == 's')
		count += puts_str(va_arg(list_args, char *));
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	else if (specifier == 'i' || specifier == 'd')
		count += puts_integer(va_arg(list_args, int));
	else if (specifier == 'b')
		count += puts_binary(va_arg(list_args, unsigned int));
	/*
	else
		count += write(1, %specifier, 1);
	*/
	return (count);
}

/**
 * _printf - produces output according to a format
 *
 * @format: a character strings
 *
 * Return: The number of characters that were printed
*/

int _printf(const char *format, ...)
{
	va_list list_args;
	int count = 0;

	va_start(list_args, format);

	if (!format || (format[0] == '%' && format[1] ==  '\0'))
		return (-1);

	while (*format != '\0')
	{
		if ((*format) == '%')
		{
			format++;
			count += print_format(*format, list_args);
		}
		else
		{
			/*return amount of bytes*/
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(list_args);
	return (count);
}
