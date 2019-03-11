/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** returns the smallest prime that is greater equal the number
*/

#include "../../include/my.h"

int is_prime(int nb)
{
    if (nb <= 0 || nb == 1)
        return (0);
    for (int compt = 2; compt < nb - 1; compt++) {
        if (nb % compt == 0)
            return (0);
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int stock = nb;

    if (is_prime(nb) != 1) {
        while (is_prime(stock) != 1)
            stock = stock + 1;
        return (stock);
    }
    return (nb);
}
