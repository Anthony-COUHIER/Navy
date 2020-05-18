/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** my_strcpy
*/

#include "lib.h"

char *my_strcpy(char *str)
{
    char *tmp;
    int size = 0;

    while (str[size] != '\0')
        size++;
    if (!(tmp = malloc(sizeof(char) * size + 1)))
        return NULL;
    for (int i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[size] = '\0';
    return tmp;
}

char *my_strncpy(char *str, int start, int max)
{
    int i = 0;
    char *tmp = NULL;
    int pos = start;

    if (!(tmp = malloc(sizeof(char) * (max - start) + 1)))
        return NULL;
    for (i = 0; str[pos] && pos < max; i++, pos++)
        tmp[i] = str[pos];
    tmp[i] = '\0';
    return tmp;
}

char *my_strtok(char *str, int pos, char c)
{
    char *tmp;
    int size = 0;

    if (!(tmp = malloc(sizeof(char) * size_word(str, pos, c) + 1)))
        return NULL;
    for (size = 0; str[pos] && str[pos] != c; size++, pos++)
        tmp[size] = str[pos];
    tmp[size] = '\0';
    return tmp;
}
