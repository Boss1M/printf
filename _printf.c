#include "main.h"
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format.
 * @format: the format
 *
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int i;
	int number;
	char* str = va_arg(args, char*);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(args, int));
				number++;
			}
			else if (*format == 's')
			{
				for (i = 0; str[i] != '\0'; i++)
				{
					putchar(str[i]);
					number++;
				}
			}
			else if (*format == '%')
			{
				 putchar('%');
				 number++;
			}
			else
				return -1;
		}
		else
		{
			putchar(*format);
			number++;
		}
	}
	va_end(args);
	return (number);
}
