/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "proto.h"

int main(int argc, char **argv)
{
    int res;
    int player = (argc == 2) ? 1 : 2;
    info.map = base_map();
    info.enemy_map = base_map();

    if (2 == argc && my_strcmp(argv[1], "-h") == 0)
        return help();
    if ((argc != 2 && argc != 3) || info.map == NULL || info.enemy_map == NULL)
        return 84;
    if (check_arg(argc, argv, info.map) == 84 || connection(argc, argv) == 84) {
        my_free_2d(info.map);
        my_free_2d(info.enemy_map);
        return 84;
    }
    res = game(player);
    my_free_2d(info.map);
    my_free_2d(info.enemy_map);
    (res == 0) ? write(1, "I won\n", 7) : write(1, "Enemy won\n", 11);
    return res;
}

int help(void)
{
    my_printf("USAGE\n");
    my_printf("\t./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tfirst_player_pid:  only for the 2nd player.");
    my_printf("  pid of the first player.\n\tnavy_positions:");
    my_printf("  file representing the positions of the ships.\n");
    return (0);
}
