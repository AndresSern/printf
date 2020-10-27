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
