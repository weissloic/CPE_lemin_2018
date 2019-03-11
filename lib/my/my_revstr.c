/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverses a string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int compt;
    char stock;

    for (compt = 0; str[compt] != '\0'; compt++);
    compt--;
    for (int carac = 0; carac != compt; carac++) {
        stock = str[carac];
        str[carac] = str[compt];
        str[compt] = stock;
        compt--;
    }
    return (str);
}
