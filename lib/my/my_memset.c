/*
** EPITECH PROJECT, 2018
** lib
** File description:
** init_func
*/

#include "../../include/my.h"

void my_memset(char *str, char value, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = value;
    str[size] = '\0';
}