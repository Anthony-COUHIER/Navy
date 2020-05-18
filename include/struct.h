/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct info
{
    int enemy_pid;
    int signal_x;
    int signal_y;
    int end_signal;
    char *pos;
    char **map;
    char **enemy_map;
    int hit_me;
    int hit_enemy;
} info_t;

#endif /* !STRUCT_H_ */
