#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: a character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			length++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				length++;
			}
			else
				if (*format == 's')
				{
					char *str = va_arg(args, char *);

					while (*str)
					{
						putchar(*str);
						length++;
						str++;
					}
				}
				else
					if (*format == '%')
					{
						putchar('%');
						length++;
					}
		}

		format++;
	}

	va_end(args);
	return (length);
}
