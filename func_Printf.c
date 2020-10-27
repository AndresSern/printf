#include "holberton.h"
/**
 * parametros - Parameters for printf
 * @f_list: list of arguments
 *
 */
int parser(const char *format, va_list arg_list)
{
	int a, b, c, chars, r_val;

	conver_t f_list[] = {{"c", _char}, {"s", _string}, {"%", _percent},
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
					r_val = f_list[b].f(arg_list);
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

