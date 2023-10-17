#ifndef PRINTF_H
#define PRINTF_H

/* flags */
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define _INT_MIN (1 << (sizeof(int) * 8 - 1))

/* functions */
int _putchar(char c);
int _putint(int num);
int _puthex2(int num);
int _putstr(char *str);
int _putnospec(char *str);
int _putbit(unsigned int num);
int _putoct(unsigned int num);
int _putuint(unsigned int num);
int _putsign(int num, char base);
int _printf(const char *format, ...);
int _puthash(unsigned int num, char base);
int _puthex(unsigned int num, char alpha);
int _spec_handler (va_list ls_args, char spec);
int _flag_handler(va_list ls_args, char spec, char base);

#endif /* PRINTF_H */
