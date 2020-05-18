/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdio.h"

#ifndef READ_SIZE
#define READ_SIZE (8)
#endif

char *get_next_line(int fd);
char *my_line(int fd, int pos);
int check_line(char *str1, int pos);
char *my_strcat_getnextline(char *str1, char *str2);
int my_strlen(char *str);

#endif /* !GET_NEXT_LINE_H_ */
