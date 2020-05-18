/*
** EPITECH PROJECT, 2020
** lib
** File description:
** input
*/

#include "lib.h"

char *my_input(void)
{
    char buff = 0;
    char *save = NULL;
    char *tmp = malloc(sizeof(char) * 1);

    tmp[0] = '\0';
    my_putstr(NORMAL_ITALIC);
    while (buff != '\n') {
        if (read(0, &buff, 1) <= 0) {
            free(tmp);
            my_printf("\n");
            return my_strcpy("00");
        }
        if (buff == '\t')
            buff = ' ';
        save = tmp;
        tmp = my_strcat_c(tmp, buff);
        free(save);
    }
    tmp[my_strlen(tmp) - 1] = '\0';
    my_putstr(NORMAL);
    return tmp;
}
