/*
** EPITECH PROJECT, 2019
** Lib/my_printf
** File description:
** putchar
*/

#include "lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;
    for (; str[i]; i++);
    write(1, str, i);
}

void my_ascii(char carac)
{
    my_putchar('\\');
    if (carac <= 7) {
        my_putstr("00");
        my_put_nbr_oct(carac);
    }
    if (carac < 32 && carac > 7) {
        my_putstr("0");
        my_put_nbr_oct(carac);
    }
    if (carac > 126 ) {
        my_put_nbr_oct(carac);
    }
}

void double_char(char **str)
{
    for (int i = 0; str[i]; i++)
        my_putstr(str[i]);
}
