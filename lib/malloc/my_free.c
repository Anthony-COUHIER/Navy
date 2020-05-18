/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_free_2d
*/

#include "lib.h"

void my_free_2d(char **str)
{
    int i = 0;

    while (str[i]) {
        free(str[i]);
        i++;
    }
    free(str);
}
