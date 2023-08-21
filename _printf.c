#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: Additional arguments based on format.
 * Return: Number of characters printed (excluding null byte).
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char c, *s;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s)
				{
					write(1, s, 1);
					s++;
					printed_chars++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
