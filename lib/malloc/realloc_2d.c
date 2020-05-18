/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** realloc_2d
*/

#include "lib.h"

char **my_realloc_2d(char **table, int value)
{
    int i = 0;
    int size = count_args(table);
    char **new = NULL;

    if (table == NULL)
        return NULL;
    new = malloc(sizeof(char *) * (size + value + 1));
    for (i = 0; table[i]; i++)
        new[i] = my_strcpy(table[i]);
    new[(size + value)] = NULL;
    return new;
}
