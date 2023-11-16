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
 * custom_printf - prints an unsigned integer
 * @n: unsigned integer to print
 *
 * Return: number of characters printed
 */
int custom_printf(unsigned int n)
{
        /* convert unsigned int to string */
        char buffer[20];

        int i = 0;

        while (n > 0)
        {
                buffer[i++] = (n % 10) + '0';
                n /= 10;
        }
        buffer[i] = '\0';

        /* reverse the string */
        int j = 0;

        i--;

        while (j < i)
        {
                char tmp = buffer[j];
                buffer[j] = buffer[i];
                buffer[i] = tmp;
                j++;
                i--;
        }

        /* print the string */
        int count = 0;

        while (buffer[count] != '\0')
        {
                count += puts_char(buffer[count]);
        }

        return (count);
}
