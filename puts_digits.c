#include "main.h"

/**
 * puts_digits - Prints an unsigned integer in binary format.
 * @value: The unsigned integer value to be printed.
 * @base: The base to be used for printing.
 *
 * Return: The number of characters printed.
 */
int puts_digits(long value, int base)
{
    int count = 0;
    char *symbols = "0123456789abcdef";

    if (value < 0)
    {
        write(1, "-", 1);
        count++;
        value = -value;
    }

    if (value < base)
    {
        count += puts_char(symbols[value]);
        return (count);
    }

    count += puts_digits(value / base, base);
    count += puts_char(symbols[value % base]);

    return (count);
}

/**
 * puts_digit_caps - Prints an unsigned integer in caps hex format.
 * @value: The unsigned integer value to be printed.
 * @base: The base to be used for printing.
 *
 * Return: The number of characters printed.
 */
int puts_digit_caps(long value, int base)
{
    int count = 0;
    char *symbols = "0123456789ABCDEF";

    if (value < 0)
    {
        write(1, "-", 1);
        count++;
        value = -value;
    }

    if (value < base)
    {
        count += puts_char(symbols[value]);
        return (count);
    }

    count += puts_digit_caps(value / base, base);
    count += puts_char(symbols[value % base]);

    return (count);
}
