#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define _INT_MIN (1 << (sizeof(int) * 8 - 1))

int _printf(const char *form, ...);
int _putcharacter(char c);
int _putstr(char *str);
int _putinteger(int numb);
int _putunsingedinteger(unsigned int numb);
int _putbit(unsigned int numb);
int _putoctal(unsigned int numb);
int _puthexadecimal(unsigned int numb, char alpha);
int _putnospecifier(char *str);
int _puthexadecimal2(int numb);
int _putsigned(int numb, char base);
int _putspaced(int numb, char base);
int _puthash(unsigned int num, char base);
int _specifier_handler(va_list ls_args, char specifier);
int _flags_handler(va_list args_list, char specifier, char base);

#endif