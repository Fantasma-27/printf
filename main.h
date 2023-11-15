#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

void print_char(int c, int *length);
void print_string(const char *str, int *length);
void print_integer(int n, int *length);

int _printf(const char *format, ...);

#endif /* MAIN_H */
