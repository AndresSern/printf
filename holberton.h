#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct formats
{
	char *sym;
	int (*f)(va_list);
}fmtsSpefier;

int _putchar(char c);
int _printf(const char *format, ...);
#endif
