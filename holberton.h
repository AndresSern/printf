#ifndef HEADER_FILE
#define HEADER_FILE


typedef struct convert
{
	char *sym;
	int (*f)(va_list);
}formatos;

int _putchar(char c);
int _printf(const char *format, ...);
#endif
