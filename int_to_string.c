#include "main.h"

/**
 * int_to_string - converts an int to str
 *
 * @num: the integer to be converted
 *
 * Return - string
*/
char* int_to_string(int num)
{
	/*allocate mem for the string and null terminator*/
	char *str = (char*)malloc(12 * sizeof(char)); /*assume a max of 12 digits*/

	/*handle mem allocation failure*/
	if (!str)
	{
		exit(EXIT_FAILURE);
	}

	int i = 0; /*for placing chars into the string*/

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

	/*reverse string (since we built it from right to left*/
	for (int j = 0; j < i / 2; j++)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];

		str[j - j - 1] = temp;
	}

	/*add null terminator*/
	str[i] = '\0';

	return (str);
}
