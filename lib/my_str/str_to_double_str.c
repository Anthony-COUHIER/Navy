/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** transform_str_to_2d
*/

#include "lib.h"

char **str_to_double_str(char *str, int pos, char c)
{
    int i = 0;
    int size = 0;
    int number = count_word(str, c);
    char **tmp = malloc(sizeof(char *) * (number + 1));

    if (str == NULL)
        return NULL;
    for (i = 0; i != number && str[pos]; i++, pos++) {
        size = size_word(str, pos, c);
        tmp[i] = malloc(sizeof(char) * size + 1);
        tmp[i] = my_strcpy_c(str, pos, c);
        tmp[i][size] = '\0';
        pos += size;
    }
    tmp[i] = '\0';
    return tmp;
}
