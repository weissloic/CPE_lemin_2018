/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** calcul the power
*/

#include "../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p != 0)
        return (nb * my_compute_power_rec(nb, p - 1));
    return (0);
}
