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
 * Return: count of chars
 */
int puts_digits(long n, int base)
{
    int count;
    char *symbols;

    symbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1, "-", 1);
        return puts_digits(-n, base) + 1;
    }
    else if (n < base)
        return puts_char(symbols[n]);

    else
    {
        count = puts_digits(n / base, base);
        return count + puts_digits(n % base, base);
    }
    
}
