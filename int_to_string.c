#include "main.h"

/**
 * int_to_string - converts an int to string, handles negative numbers, exact digits and reverses the string
 *
 * @num: the integer to be converted
 *
 * Return: a pointer to resulting string
*/
char* int_to_string(int num)
{
    if (num == 0)
    {
        char* str = (char*)malloc(2 * sizeof(char));
        if (!str)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    int sign = (num < 0) ? -1 : 1;
    num = abs(num); // Make num positive

    // Calculate the number of digits
    int digits = 1;
    int temp = num;
    while (temp >= 10)
    {
        digits++;
        temp /= 10;
    }

    char* str = (char*)malloc((digits + 1 + (sign == -1)) * sizeof(char));
    if (!str)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (num > 0)
    {
        int digit = num % 10;
        str[i++] = '0' + digit;
        num /= 10;
    }

    if (sign == -1)
        str[i++] = '-';

    // Reverse the string
    int j = 0;
    while (j < i / 2)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
        j++;
    }

    str[i] = '\0';
    return str;
}
