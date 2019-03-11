/*
** EPITECH PROJECT, 2018
** my_is_prime.c
** File description:
** prime sup
*/

#include "../../include/my.h"

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1)
        return (0);
    for (int i = 2; i < nb - 1; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
