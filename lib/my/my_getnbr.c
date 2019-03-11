/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** write a function that returns number
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int rslt = 0;
    int sign = 1;
    int compt = 0;

    while (str[compt] <= 47 || str[compt] >= 58) {
        if (str[compt] == '-')
            sign = sign * (-1);
        compt++;
    }
    while (str[compt] > 47 && str[compt] < 58) {
        rslt = rslt * 10 + (str[compt] - 48);
        compt++;
    }
    rslt = sign * rslt;
    return (rslt);
}
