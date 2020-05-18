/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
*/

#include "proto.h"

int game(int player)
{
    info.hit_enemy = 0;
    info.hit_me = 0;

    while (info.hit_me != 14 && info.hit_enemy != 14) {
        info.end_signal = 0;
        info.signal_x = 0;
        info.signal_y = 0;
        my_printf("%s%S\n", "my positions:\n", info.map);
        my_printf("%s%S\n", "enemy's positions:\n", info.enemy_map);
        (player == 1) ? player_one() : player_two();
        free(info.pos);
        signal(SIGUSR1, SIG_DFL);
        signal(SIGUSR2, SIG_DFL);
    }
    my_printf("%s%S\n", "my positions:\n", info.map);
    my_printf("%s%S\n", "enemy's positions:\n", info.enemy_map);
    return (info.hit_enemy == 14) ? 0 : 1;
}

void player_one(void)
{
    info.pos = get_attack();

    usleep(500);
    send(info.pos);
    hit_or_miss();
    if (info.hit_enemy == 14 || info.hit_me == 14)
        return;
    free(info.pos);
    my_putstr("waiting for enemy's attack...");
    info.pos = receive();
    check_touch();
}

void player_two(void)
{
    my_putstr("waiting for enemy's attack...");
    info.pos = receive();
    check_touch();
    if (info.hit_me == 14 || info.hit_enemy == 14)
        return;
    free(info.pos);
    info.pos = get_attack();
    send(info.pos);
    hit_or_miss();
}

char *get_attack(void)
{
    char *attack;

    my_putstr("attack: ");
    attack = my_input();
    while (check_pos(attack) != 0) {
        free(attack);
        my_putstr("wrong position\nattack: ");
        attack = my_input();
    }
    return attack;
}
