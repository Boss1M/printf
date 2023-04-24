#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: format of character.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	char ch;
	
	while ((ch = *format++) != '\0')
	{
		if (ch == '%')
		{
			ch = *format++;
			if (ch == 'c') {
				putchar(va_arg(args, int));
			       	count++;
			}
			else if (ch == 's')
			{
				char *s = va_arg(args, char *);
				while (*s != '\0')
				{
					putchar(*s++);
					count++;
				}
			}
            else if (ch == '%') {
                putchar('%');
                count++;
            }
            else {
                return -1;  // unsupported conversion specifier
            }
        }
        else {
            putchar(ch);
            count++;
        }
    }

    va_end(args);

    return count;
}

