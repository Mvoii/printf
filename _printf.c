#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: a character strings
 *
 * Return: The number of characters that were printed
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;

	while (*format != '\0')
	{
		if ((*format) == '%')
			count =+ print_format(*(format++), ap);
		else
			/*return amount of bytes*/
			count =+ write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

/*prints char*/
int puts_char(int c)
{
	return (write(1, &c, 1));
}

/*prints strings*/
int puts_str(char *str)
{
	int count;

	count = 0;

	while (*str != '\0')
	{
		puts_char((int)*str);
		count++;
		str++;
	}
	return count;
}

/**
 * print_format - writes data formatted against some parameters
 * @ap: the arguemnts list
 * @specifier: identifies the data type
 *
 */
int print_format(char specifier, va_list ap)
{
	int count = 0; 

	/*handles char*/
	if (specifier == 'c')
		count =+ puts_char(va_arg(ap, int));

	else if (specifier == 's')
		count =+ puts_str(va_arg(ap, char *));
	return (count);

}
