/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "../lib/include/lib.h"
#include <signal.h>
#include <sys/types.h>
#include "struct.h"

info_t info;

int main(int argc, char **argv);
int help(void);
char **base_map(void);
int connection(int argc, char **argv);
void hd(int sig, siginfo_t *action, UNUSED void *ucontext);
int check_arg(int argc, char **argv, char **map);
int files_player_1(char **argv, char **map1);
int files_player_2(char **argv, char **map2);
int fill_map(int fd, char **map);
int check_value(char *pos);
int check_len(char *pos);
int check_format(char *pos);
int get_boat(char *value, char **map);
int get_boat_on_x(char **map, char *value);
int get_boat_on_y(char **map, char *value);

int game(int player);
char *get_attack(void);
int check_pos(char *attack);
char *check_order(char *attack);
void player_one(void);
void output(char *attack);
void player_two(void);
char *get_attack(void);

void send(char *attack);
char *receive(void);
void gest(int sig);
void hit_or_miss(void);
void check_touch(void);
#endif /* !PROTO_H_ */
