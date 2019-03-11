/*
** EPITECH PROJECT, 2018
** my_computer_square_root.c
** File description:
** print the square root of a number
*/

#include "../../include/my.h"

int exept(int nb, int compt)
{
    if (compt * compt > nb)
        return (0);
    return (compt);
}

int my_compute_square_root(int nb)
{
    int compt = 0;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    for (int compt = 1; compt < nb; compt++) {
        if (compt * compt == nb) {
            exept(nb, compt);
        }
    }
    return (0);
}
