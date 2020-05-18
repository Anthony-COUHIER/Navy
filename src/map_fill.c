/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** map_fill
*/

#include "proto.h"

int get_boat(char *value, char **map)
{
    if (value[2] == value[5] && value[3] != value[6])
        return get_boat_on_y(map, value);
    else if (value[3] == value[6] && value[2] != value[5])
        return get_boat_on_x(map, value);
    else
        return 84;
}

int get_boat_on_x(char **map, char *value)
{
    int x = 0;
    int y = 0;
    int check;
    int len = value[0] - '0';

    check = (value[2] < value[5]) ? value[5] - value[2] : value[2] - value[5];
    if ((check + 1) != len)
        return 84;
    for (x = 0; map[x][0] != value[3]; x++);
    for (y = 0; map[0][y] != value[2]; y++);
    for (int i = 0; i != len; i++,  y += (value[2] < value[5]) ? 2 : -2) {
        if (map[x][y] != ' ' && map[x][y] != '.')
            return 84;
        map[x][y] = value[0];
    }
    return 0;
}

int get_boat_on_y(char **map, char *value)
{
    int i = 0;
    int y = 0;
    int x = 0;
    int check;
    int len = value[0] - '0';

    check = (value[3] < value[6]) ? value[6] - value[3] : value[3] - value[6];
    if ((check + 1) != len)
        return 84;
    for (x = 0; map[x][0] != value[3]; x++);
    for (y = 0; map[0][y] != value[2]; y++);
    for (i = 0; i != len; i++, (value[3] < value[6]) ? x++ : x--) {
        if (map[x][y] != ' ' && map[x][y] != '.')
            return 84;
        map[x][y] = value[0];
    }
    return 0;
}
