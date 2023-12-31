#include "shell.h"

/**
* interactive - returns true if shell is interactive mode
* @info: struct address
*
* Return: 1 if interactive mode, 0 otherwise
*/

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
* is_delim - checks if character is a delimeter
* @charact: the char to check
* @delim: the delimeter string
* Return: 1 if true, 0 if false
*/
int is_delim(char charact, char *delim)
{
	while (*delim)
		if (*delim++ == charact)
			return (1);
	return (0);
}

/**
*_isalpha - checks for alphabetic character
*@charact: The character to input
*Return: 1 if c is alphabetic, 0 otherwise
*/
int _isalpha(int charact)
{
	if ((charact >= 'a' && charact <= 'z') || (charact >= 'A' && charact <= 'Z'))
		return (1);
	else
		return (0);
}

/**
*_atoi - converts a string to an integer
*@str: the string to be converted
*Return: 0 if no numbers in string, converted number otherwise
*/
int _atoi(char *str)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0;  str[a] != '\0' && flag != 2; a++)
	{
		if (str[a] == '-')
			sign *= -1;
		if (str[a] >= '0' && str[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
