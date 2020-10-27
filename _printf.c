#include "holberton.h"


/**
 * parametros - Parameters for printf
 * @f_list: list of arguments
 *
 */

int _printf(const char *format, ...)
{
	int chars;
	va_list list;
	
	va_start (list, format);
	if (format == NULL)
		return (-1);

	chars = charsFormats(format, list);

	va_end(list);
	return chars;
}
int charsFormats(const char *format, va_list valist)
{
	int i = 0, j = 0, printedCharacters = 0;
	fmtsSpefier dataType[] = {{"c", _char}, {"s",_string}};

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			if (format[i + 1] == '%')
			{
				printedCharacters += _putchar ('%');
				i++;
			}
			else if (format[i + 1] == ' ')
			{
				while (format[i + 1] == ' ')
					i++;
				printedCharacters += _putchar('%');
				printedCharacters += _putchar(' ');
			}
			else
			{
				for (j = 0; j < 2; j++)
				{
					if (format[i + 1] == dataType[j].sym[0])
					{
						printedCharacters += dataType[j].f(valist);
						i++;
						break;
					}
				}
				if (j == 2)
					printedCharacters += _putchar('%');
			}
		}
		else
			printedCharacters += _putchar (format[i]);
		i++;
	}
	return (printedCharacters);
}
