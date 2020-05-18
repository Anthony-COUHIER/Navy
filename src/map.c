/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** map
*/

#include "proto.h"

int check_arg(int argc, char **argv, char **map)
{
    if (argc == 2) {
        return files_player_1(argv, map);
    } else if (argc == 3) {
        return files_player_2(argv, map);
    } else {
        write(1, "Bad args\n", 10);
        return 84;
    }
}

int files_player_1(char **argv, char **map)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        write(1, "Can't open\n", 12);
        return 84;
    } else if (fill_map(fd, map) == 84) {
        write(1, "Bad files\n", 11);
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}

int files_player_2(char **argv, char **map)
{
    int fd;

    fd = open(argv[2], O_RDONLY);
    if (fd == -1) {
        write(1, "Can't open\n", 12);
        return 84;
    } else if (fill_map(fd, map) == 84) {
        write(1, "Bad files\n", 11);
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}

int fill_map(int fd, char **map)
{
    int nbr;
    char *value = get_next_line(fd);

    for (nbr = 0; value != NULL; nbr++) {
        if (check_value(value) == 84 || get_boat(value, map))
            return 84;
        free(value);
        value = get_next_line(fd);
    }
    if (nbr != 4) {
        return 84;
    }
    return 0;
}
