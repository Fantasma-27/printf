#include "main.h"
#include <stdio.h>
<<<<<<< HEAD

/**
 * _printf - produces output according to a format
 * @format: a character string composed of zero or more directives
 *
 * Return: number of characters printed (excluding null byte)
 */

=======
#
>>>>>>> 9481de5a0c17c159d199af02b5840ba8da34cd38
int _printf(const char *format, ...)
{
  va_list args;
  int count = 0;
  char *str;
  char c;

  va_start(args, format);

  while (*format != '\0')
    {
      if (*format == '%')
	{
	  format++;
	  switch (*format)
	    {
	    case 'c':
	      c = va_arg(args, int);
	      putchar(c);
	      count++;
	      break;
	    case 's':
	      str = va_arg(args, char *);
	      while (*str)
		{
		  putchar(*str);
		  count++;
		  str++;
		}
	      break;
	    case '%':
	      putchar('%');
	      count++;
	      break;
	    default:
	      putchar('%');
	      putchar(*format);
	      count += 2;
	      break;
	    }
	}
      else
	{
	  putchar(*format);
	  count++;
	}
      format++;
    }

  va_end(args);
  return count;
}

