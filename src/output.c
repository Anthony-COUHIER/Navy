/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** output
*/

#include "proto.h"

void send(char *attack)
{
    for (int out = attack[0] - 64; out > 0; out--) {
        usleep(500);
        kill(info.enemy_pid, SIGUSR1);
    }
    usleep(500);
    kill(info.enemy_pid, SIGUSR2);
    for (int out = attack[1] - 48; out > 0; out--) {
        usleep(500);
        kill(info.enemy_pid, SIGUSR1);
    }
    usleep(500);
    kill(info.enemy_pid, SIGUSR2);
}

void gest(int sig)
{
    if (sig == SIGUSR1 && info.end_signal == 0) {
        info.signal_x++;
    } else if (sig == SIGUSR1 && info.end_signal == 1)
        info.signal_y++;
    if (sig == SIGUSR2)
        info.end_signal++;
}

char *receive(void)
{
    char *input = malloc(sizeof(char) * 2 + 1);
    signal(SIGUSR1, gest);
    signal(SIGUSR2, gest);

    while (info.end_signal != 2)
        pause();
    input[0] = info.signal_x + 64;
    input[1] = info.signal_y + 48;
    input[2] = '\0';
    return input;
}
