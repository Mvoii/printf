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
	char *str;
	int i = 0;
	int j = 0;

	if (num == 0)
	{
		/*allocate mem for the string and null terminator*/
		str = (char*)malloc(2 * sizeof(char));

		if (!str)
		{
			perror("Memory allocataion failed");
			exit(EXIT_FAILURE);
		}
		str[0] = '0';
		str[1] = '\0';

		return (str);
	}

	/*handle negative numbers*/
	int sign = (num < 0) ? -1 : 1;
	num = abs(num); /*make num positive*/

	/*extract digits and convert to characters*/
	int digits = 1;
	int temp = num;

	while (temp >= 10)
	{
		digit++;
		temp /= 10;
	}

	str = (char *)malloc((digits + 1 + (sign == -1)) * sizeof(char));
	if(!str)
	{
		perror("Memory allocation Failed");
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
	{
		str[i++] = '-';
	}

	/*reverse string (since we built it from right to left)*/
	while (j < i / 2)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
		j++;
	}

	/*add null terminator*/
	str[i] = '\0';

	return (str);
}
