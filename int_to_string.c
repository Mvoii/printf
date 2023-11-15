#include "main.h"

/**
 * int_to_string - converts an int to string
 *
 * @num: the integer to be converted
 *
 * Return: a pointer to resulting string
*/
char* int_to_string(int num)
{
	char *str;
	int i = 0;
	int j = 0;

	/*allocate mem for the string and null terminator*/
	str = (char*)malloc(12 * sizeof(char)); /*assume a max of 12 digits*/

	if (!str)
	{
		perror("Memory alocataion failed");
		exit(EXIT_FAILURE);
	}

	/*handle negative numbers*/
	if (num < 0)
	{
		str[i++] = '-';
		num = -num; /*make num positive*/
	}

	/*extract digits and convert to characters*/
	while (num > 0)
	{
		int digit = num % 10;

		str[i++] = '0' + digit;
		num /= 10;
	}

	/*reverse string (since we built it from right to left)*/
	while (j < i / 2)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];
		str[j - j - 1] = temp;
		j++;
	}

	/*add null terminator*/
	str[i] = '\0';

	return (str);
}
