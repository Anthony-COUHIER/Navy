/*
** EPITECH PROJECT, 2019
** lib/my_printf
** File description:
** my_printf
*/

#include "lib.h"

void my_printf(char *format, ...)
{
    va_list ap;
    int j = 0;
    int i = 0;

    for (; format[j]; j++);
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            my_flags(format, i, ap);
            if (format[i] == 'h' || format[i] == 'l')
                i++;
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
}

void my_flags(char *format, int i, va_list ap)
{
    while ((format[i] == '#' || format[i] == '+' || format[i] == '-'
    || format[i] == ' ' || (format[i] <= '9' && format[i] >= '0')))
        i++;
    cond_1(format, i, ap);
}

void cond_1(char *form, int i, va_list ap)
{
    (form[i] == '%') ? my_putchar('%') : 0;
    (form[i] == 'c') ? my_putchar(va_arg(ap, int)) : 0;
    (form[i] == 's') ? my_putstr(va_arg(ap, char *)) : 0;
    (form[i] == 'S') ? double_char(va_arg(ap, char **)) : 0;
    (form[i] == 'd' || form[i] == 'i') ? my_put_nbr_dec(va_arg(ap, int)) : 0;
    (form[i] == 'x') ? my_put_nbr_hex(va_arg(ap, int), form[i], 16) : 0;
    (form[i] == 'X') ? my_put_nbr_hex(va_arg(ap, int), form[i], 16) : 0;
    (form[i] == 'o') ? my_put_nbr_oct(va_arg(ap, int)) : 0;
    (form[i] == 'b') ? my_put_nbr_bin(va_arg(ap, int)) : 0;
    (form[i] == 'u') ? my_put_unint(va_arg(ap, unsigned int)) : 0;
    if (form[i] == 'p') {
        my_putstr("0x");
        my_put_nbr_hex((long) va_arg(ap, void *), form[i], 16);
    }
    cond_2(form, i, ap);
}

void cond_2(char *format, int i, va_list ap)
{
    if (format[i] == 'l' && format[i + 1] == 'd')
        my_put_long(va_arg(ap, long));
    if (format[i] == 'h' && format[i + 1] == 'd')
        my_put_short(va_arg(ap, int));
    if (format[i] != '%' && format[i] != 'c' && format[i] != 's' &&
    format[i] != 'S' && format[i] != 'd' && format[i] != 'i' && format[i] != 'x'
    && format[i] != 'X' && format[i] != 'o' && format[i] != 'b' &&
    format[i] != 'u' && format[i] != 'p' && format[i] != 'l' &&
    format[i] != 'h') {
        my_putchar('%');
        my_putchar(format[i]);
    }
    if ((format[i] == 'l' || format[i] == 'h') && format[i + 1] != 'd') {
        my_putchar('%');
        my_putchar(format[i]);
        my_putchar(format[i] + 1);
    }
}
