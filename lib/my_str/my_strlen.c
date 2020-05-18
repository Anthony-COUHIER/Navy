/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** my_strlen
*/

#include "lib.h"

int my_strlen(char *str)
{
    int size = 0;

    while (str[size])
        size++;
    return size;
}
