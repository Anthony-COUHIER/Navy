/*
** EPITECH PROJECT, 2020
** hit or miss.c
** File description:
** hit or miss
*/

#include "proto.h"

void touch(int sig)
{
    int pos_x = 0;
    int pos_y = 0;

    for (pos_x = 0; info.map[0][pos_x] != info.pos[0]; pos_x++);
    for (pos_y = 0; info.map[pos_y][0] != info.pos[1]; pos_y++);
    if (sig == SIGUSR2) {
        my_printf("%s%s", info.pos, ": missed\n\n");
        info.enemy_map[pos_y][pos_x] = 'o';
    } else if (sig == SIGUSR1) {
        my_printf("%s%s", info.pos, ": hit\n\n");
        info.enemy_map[pos_y][pos_x] = 'x';
        info.hit_enemy++;
    }
}

void hit_or_miss(void)
{
    signal(SIGUSR1, touch);
    signal(SIGUSR2, touch);
    pause();
}

void check_touch(void)
{
    int pos_x = 0;
    int pos_y = 0;

    for (pos_x = 0; info.map[0][pos_x] != info.pos[0]; pos_x++);
    for (pos_y = 0; info.map[pos_y][0] != info.pos[1]; pos_y++);
    usleep(500);
    if (info.map[pos_y][pos_x] != '.' && info.map[pos_y][pos_x] != 'o' &&
    info.map[pos_y][pos_x] != 'x' ) {
        my_printf("\n%s%s", info.pos, ": hit\n\n");
        info.map[pos_y][pos_x] = 'x';
        info.hit_me++;
        kill(info.enemy_pid, SIGUSR1);
    } else {
        my_printf("\n%s%s", info.pos, ": missed\n\n");
        info.map[pos_y][pos_x] = 'o';
        kill(info.enemy_pid, SIGUSR2);
    }
}
