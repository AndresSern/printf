#include "holberton.h"


/**
 * _printf - Parameters for printf
 * @format: list of arguments
 * Return: Printed thing
 */

int _printf(const char *format, ...)
{
	int chars;
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);

	chars = charsFormats(format, list);

	va_end(list);
	return (chars);
}

/**
 * charsFormats - paremters printf
 * @format: list of arguments
 * @args: listing
 * Return: value of print
 */

int charsFormats(const char *format, va_list args)
{
	int a, b, chars, r_val;

	fmtsSpefier f_list[] = {{"c", _char}, {"s", _string},
				{"%", _percent}, {"d", _integer}, {"i", _integer}, {NULL, NULL}
	};
	chars = 0;
	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] == '%')
		{
			for (b = 0; f_list[b].sym != NULL; b++)
			{
				if (format[a + 1] == f_list[b].sym[0])
				{
					r_val = f_list[b].f(args);
					if (r_val == -1)
						return (-1);
					chars += r_val;
					break;
				}
			}
			if (f_list[b].sym == NULL && format[a + 1] != ' ')
			{
				if (format[a + 1] != '\0')
				{
					_putchar(format[a]);
					_putchar(format[a + 1]);
					chars = chars + 2;
}
				else
					return (-1);
			}
		a += 1;
		}
		else
		{
			_putchar(format[a]);
			chars++;
		}
	}
	return (chars);
}
