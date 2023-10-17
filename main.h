#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>

/**
 *struct print - contains a printf flag and related function
 *@type: the flag
 *@func: the function
 */

typedef struct print
{
	char type;
	int (*func)(va_list);
} print_table;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_perc(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int print_b(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_S(va_list args);
char *print_conv(unsigned long int num, int base, int cap);
int print_r(va_list args);
int print_p(va_list args);
int print_R(va_list args);

#endif
