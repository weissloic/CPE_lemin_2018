/*
** EPITECH PROJECT, 2018
** base.c
** File description:
** all the function for display octal binarie hexa base
*/

#include "../../include/my.h"

int calc_convert_tobase(int nbr, char *base)
{
    int base_len = my_strlen(base);

    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    if (nbr == 0) {
        return (0);
    } else {
        calc_convert_tobase(nbr / base_len, base);
    }
    my_putchar(base[nbr % base_len]);
    return (0);
}

void display_octo(va_list var)
{
    calc_convert_tobase(va_arg(var, int), "01234567");
}

void display_bin(va_list var)
{
    calc_convert_tobase(va_arg(var, int), "01");
}

void display_hexa_up(va_list var)
{
    calc_convert_tobase(va_arg(var, int), "0123456789ABCDEF");
}

void display_hexa_low(va_list var)
{
    calc_convert_tobase(va_arg(var, int), "0123456789abcdef");
}