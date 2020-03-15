#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{NULL, NULL}
	};

	while (find_f[i].sc)
	{
		if (find_f[i].sc[0] == *format)
			break;
		i++;
	}
	return (find_f[i].f);
}
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		if (!format[i + 1])
			return (-1);
		f = find_function(format[i + 1]);
		if (f != NULL)
		{
			cprint += f(ap);
			i += 2;
		}
		if (format[i + 1] == '%')
			_putchar('%');
			i += 2;
		else 
			i++;
	}
	va_end(ap);
	return (cprint);
}