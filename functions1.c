#include "holberton.h"
/**
 * prtChar - print characters
 * @list: arguments
 * Return: how many characters has been printed
 */
int prtChar(va_list list)
{
	put_char(va_arg(list, int));
	return (1);
}

/**
 * print_string - Print a string
 * @list: arguments
 * Return: how many characters has been printed
 */
int print_string(va_list list)
{
	int a;
	char *string;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	for (a = 0; string[a] != '\0'; i++)
		put_char(string[a]);
	return (a);
}

/**
 *
 *
 */
int print_percent(va_list list)
