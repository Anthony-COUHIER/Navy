/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** map_fill
*/

#include "proto.h"

char **base_map(void)
{
    char **base = malloc(sizeof(char *) * (10 + 1));

    if (!base)
        return NULL;
    base[0] = my_strcpy(" |A B C D E F G H\n");
    base[1] = my_strcpy("-+---------------\n");
    base[2] = my_strcpy("1|. . . . . . . .\n");
    base[3] = my_strcpy("2|. . . . . . . .\n");
    base[4] = my_strcpy("3|. . . . . . . .\n");
    base[5] = my_strcpy("4|. . . . . . . .\n");
    base[6] = my_strcpy("5|. . . . . . . .\n");
    base[7] = my_strcpy("6|. . . . . . . .\n");
    base[8] = my_strcpy("7|. . . . . . . .\n");
    base[9] = my_strcpy("8|. . . . . . . .\n");
    base[10] = '\0';
    return base;
}

int check_value(char *pos)
{
    if (check_len(pos) == 84 || check_format(pos) == 84)
        return 84;
    else
        return 0;
}

int check_len(char *pos)
{
    static int len_2 = 0;
    static int len_3 = 0;
    static int len_4 = 0;
    static int len_5 = 0;

    if (my_strlen(pos) != 7)
        return 84;
    else if ((pos[0] == '2' && len_2 == 0) || (pos[0] == '3' && len_3 == 0) ||
    (pos[0] == '4' && len_4 == 0) || (pos[0] == '5' && len_5 == 0)) {
        (my_atoi(pos) == 2) ? len_2 = 1 : 0;
        (my_atoi(pos) == 3) ? len_3 = 1 : 0;
        (my_atoi(pos) == 4) ? len_4 = 1 : 0;
        (my_atoi(pos) == 5) ? len_5 = 1 : 0;
        return 0;
    } else
        return 84;
}

int check_format(char *pos)
{
    if ((pos[3] < '1' || pos[3] > '8') || (pos[6] < '1' && pos[6] > '8') ||
    (pos[2] < 'A' || pos[2] > 'H') || (pos[5] < 'A' || pos[5] > 'H') ||
    (pos[1] != ':'  || pos[4] != ':'))
        return 84;
    else
        return 0;
}
