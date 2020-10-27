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

	chars = charsFormats(forma, list);

	va_end(list);
	return chars;
}
int charsFormats(const char *format, va_list args)
{
	int a, b, c, chars, r_val;

	fmtsSpefier f_list[] = {{"c", _char}, {"s", _string}, {"%", _percent},
	{NULL, NULL}
	};
	for (a = 0; format[a]; a++)
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
					put_char(format[a]);
					put_char(format[a + 1]);
					chars += 2;
 				}
				else
					return (-1);
			}
		a += 1;
		}
		else
		{
			chars(format[a]); /*call the write function*/
			chars++;
		}
	}
	return (chars);
}

