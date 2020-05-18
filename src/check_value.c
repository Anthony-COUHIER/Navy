/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check_value
*/

#include "proto.h"

int check_pos(char *attack)
{
    char *tmp = check_order(attack);

    if (tmp[0] >= 'A' && tmp[0] <= 'H' && tmp[1] >= '1' && tmp[1] <= '8') {
        return 0;
    } else
        return 84;
}

char *check_order(char *attack)
{
    char tmp;

    if (attack[0] >= '1' && attack[0] <= '9') {
        tmp = attack[0];
        attack[0] = attack[1];
        attack[1] = tmp;
        return attack;
    }
    return attack;
}
