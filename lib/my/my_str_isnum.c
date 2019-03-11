/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** is num str
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    if (*str == '-')
        str++;
    while (*str != '\0' && *str != '\n') {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}
