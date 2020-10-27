#include "holberton.h"
/**
 * parametros - Parameters for printf
 * @f_list: list of arguments
 *
 */

void parametros(void)
{
	conver_t f_list[] = {
	{"c", _char},
	{"s", _string},
	{"%", _percent},
	{"d", _integer},
	{"i", _integer},
	{"b", _binary},
	{"r", _reversed},
	{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
}
