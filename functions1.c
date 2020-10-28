#include "holberton.h"
/**
 * _char - print characters
 * @list: arguments
 * Return: how many characters has been printed
 */
int _char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * _string - Print a string
 * @list: arguments
 * Return: how many characters has been printed
 */
int _string(va_list list)
{
	int a;
	char *string;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	for (a = 0; string[a] != '\0'; a++)
		_putchar(string[a]);
	return (a);
}

/**
 * _percent - print %
 * @list: arguments
 * Return: specific character
 */
int _percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * _integer - prints integer
 * @list: va_list variable
 * Return: prints given number of integers
 */

int _integer(va_list list)
{
	int num1 = va_arg(list, long int), num2;
	int div = 1, i = 0;

	if (num1 < 0)
	{
		_putchar('-');
		i++;
		num1 *= -1;
	}
	num2 = num1;
	while (num2 > 9)
	{
		div *= 10;
		num2 = num2 / 10;
	}
	while (div >= 1)
	{
		num2 = num1 % div;
		num1 /= div;
		_putchar(num1 + '0');
		num1 = num2;
		div /= 10;
		i++;
	}
	return (i);
}


