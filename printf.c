#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a character
 * @c: character to print
 * @length: pointer to the length variable
 */
void print_char(int c, int *length)
{
	putchar(c);
	(*length)++;
}

/**
 * print_string - Prints a string
 * @str: String to print
 * @length: Pointer to the length variable
 */
void print_string(const char *str, int *length)
{
	while (str && *str)
	{
		putchar(*str);
		(*length)++;
		str++;
	}
}

/**
 * print_integer - Prints an integer
 * @n: Integer to print
 * @length: Pointer to the length variable
 */
void print_integer(int n, int *length)
{
	printf("%d", n);
	*length += snprintf(NULL, 0, "%d", n);
}

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
			print_char(*format, &length);
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				int c = va_arg(args, int);
				print_char(c, &length);
			}
			else
				if (*format == 's')
				{
					char *str = va_arg(args, char *);
					print_string(str, &length);
				}
				else
					if (*format == 'd' || *format == 'i')
					{
						int num = va_arg(args, int);
						print_integer(num, &length);
					}
					else
						if (*format == '%')
						{
							print_char('%', &length);
						}
		}

		format++;
	}

	va_end(args);
	return (length);
}
