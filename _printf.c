#include "main.h"

/**
 * puts_char - writes data
 *
 * @c: the char to be printed
 *
 * Return: count of bytes
*/
int puts_char(int c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * puts_str - prints strings
 * 
 * @str: a string of chars
 *
 * Returns: count of printed bytes
*/
int puts_str(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count += puts_char((int)*str);
		str++;
	}
	return (count);
}

/**
 * puts_integer - prints out integers
 * @value: integer value to be printed
 * @value_str: initializes teh variable space
 * Returns: number of characters printed
*/
int puts_integer(int value)
{
	char value_str[20];
	int num_chars_printed;

	num_chars_printed = snprintf(value_str, sizeof(value_str), "%d", value);

	num_chars_printed = puts_str(value_str);
	return (num_chars_printed);
}

/**
 * Prints an unsigned integer in binary format.
 * @param value The unsigned integer value to be printed.
 */
int puts_binary(unsigned int value)
{
	int count = 0;

	/*create a mask to extract each bit*/
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

	/*iterate through each bit and print it*/
	while (mask > 0)
	{
		if (value & mask)
			count += puts_char('1');
		else
			count += puts_chars('0');
		mask >>= 1; /*shifts mask to the right*/
	}
	return (count);
}

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
