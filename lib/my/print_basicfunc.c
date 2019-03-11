/*
** EPITECH PROJECT, 2018
** printf_int.c
** File description:
** functions for display int.
*/

#include "../../include/my.h"

long calc_pointer(long nbr, char *base)
{
    int base_len = my_strlen(base);

    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    if (nbr == 0) {
        return (0);
    } else {
        calc_pointer(nbr / base_len, base);
    }
    my_putchar(base[nbr % base_len]);
    return (0);
}

void display_int(va_list var)
{
    my_put_nbr(va_arg(var, int));
}

void display_char(va_list var)
{
    my_putchar(va_arg(var, int));
}

void display_str(va_list var)
{
    my_putstr(va_arg(var, char *));
}

void display_pointer(va_list var)
{
    my_putstr("0x");
    calc_pointer(va_arg(var, long), "0123456789abcdef");
}