#include "main.h"
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
