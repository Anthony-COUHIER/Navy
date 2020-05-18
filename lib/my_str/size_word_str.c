/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** size_word_str
*/

#include "lib.h"

int size_word(char *str, int pos, char c)
{
    int size = 0;

    while (str[pos] && str[pos] == c)
        pos++;
    while (str[pos] && str[pos] != c) {
        size++;
        pos++;
    }
    return size;
}
