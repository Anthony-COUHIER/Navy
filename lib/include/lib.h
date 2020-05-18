/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

#include "../getnextline/get_next_line.h"
#include "../include/define.h"
#include "fcntl.h"
#include "stdlib.h"
#include "stdarg.h"
#include "unistd.h"
#include "color.h"

void my_printf(char *format, ...);
void my_flags(char *format, int i, va_list ap);
void cond_1(char *format, int i, va_list ap);
void cond_2(char *format, int i, va_list ap);
void cond_3(char *format, int i, va_list ap);
void my_put_short(short nb);
void my_put_long(long nb);
void my_put_nbr_hex(long nb, char format, int hex);
void my_put_nbr_oct(int nb);
void my_put_nbr_bin(int nb);
void my_put_nbr_dec(int nb);
int my_put_unint(unsigned int nb);
int isneg(int nb);
void my_putstr(char *str);
void my_putchar(char c);
void double_char(char **str);
void my_ascii(char carac);

void my_free_2d(char **str);
char **my_realloc_2d(char **table, int value);

int my_strlen(char *str);
char *my_strcat(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int max);
char *my_strcpy(char *str);
char *my_strncpy(char *str, int start, int max);
char *my_strcpy_c(char *str, int pos, char c);
char *my_strcat_c(char *str1, char c);
char **str_to_double_str(char *str, int pos, char c);
int count_word(char *str, char c);
int size_word(char *str, int pos, char c);
int count_args(char **args);
int check_alphanum(char *args);

char *my_input(void);
int my_atoi(char *str);
#endif /* !LIB_H_ */
