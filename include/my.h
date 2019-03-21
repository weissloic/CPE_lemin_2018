/*
** EPITECH PROJECT, 2018
** mylib.h
** File description:
** list all the function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef MY_H_
#define MY_H_

// BASIC FUNCTION
void my_putchar(char );
int my_isneg(int );
int my_put_nbr(int );
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);

// FUNC
void my_sort_in_array(int *, int);
int my_compute_power_rec(int , int);
int my_compute_square_root(int );
int my_is_prime(int );
int my_find_prime_sup(int );

// STR
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);
char *my_strncpy(char *, char const *, int );
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const * , int );
// find
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
//other
int my_showstr(char const *);
int my_showmem(char const * , int );
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const * , int );
int my_show_word_array(char *const *);

// PRINTF FUNC
int calc_convert_tobase(int , char *);
long calc_pointer(long , char *);
void my_putfloat(double , int );
void my_putunsignd(long );
void my_big_s(unsigned char *);
void my_printf(char *, ...);
void check_error(int , int , char *, va_list );

// DISPLAY FUNC
// base
void display_octo(va_list );
void display_bin(va_list );
void display_hexa_up(va_list );
void display_hexa_low(va_list );
void display_pointer(va_list );

// basic
void display_str(va_list );
void display_char(va_list );
void display_int(va_list );
void display_float(va_list );
// other
void display_strbis(va_list );
void display_percent(va_list );
void display_unsigned(va_list );
void error_big_s(unsigned char );

#endif //MY_H_