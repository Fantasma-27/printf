#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
  int printdchars = 0;
  va_list argslist;

  if (format == NULL) {
    return -1;
  }

  va_start(argslist, format);

  while (*format != '\0') {
    if (*format != '%') {
      putchar(*format);
      printdchars++;
    } else {
       format++;
      if (*format == 'c') {
	int c = va_arg(argslist, int);
	putchar(c);
	printdchars++;
      } else if (*format == 's') {
	char *str = va_arg(argslist, char *);
	while (*str != '\0') {
	  putchar(*str);
	  printdchars++;
	  str++;
        }
      } else if (*format == '%'){
	putchar('%');
	printdchars++;
    }
    format++;
  }

  va_end(argslist);

  return printdchars;
}