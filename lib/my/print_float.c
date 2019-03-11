/*
** EPITECH PROJECT, 2018
** print_float.c
** File description:
** function for print float number
*/

#include "../../include/my.h"

void my_putfloat(double nbr, int precision)
{
    int stock = 0;

    stock = nbr;
    my_put_nbr(stock);
    nbr = nbr - stock;
    my_putchar('.');
    for (stock = 0; precision > 1; precision--) {
        nbr = nbr * 10;
        stock = nbr;
        my_put_nbr(stock);
        nbr = nbr - stock;
    }
    nbr = nbr * 10;
    stock = nbr;
    my_put_nbr(stock);
}

void my_big_s(unsigned char *chaine)
{
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] >= 32 && chaine[i] < 127)
            my_putchar(chaine[i]);
        else if (chaine[i] < 32) {
            error_big_s(chaine[i]);
        } else {
            my_putchar('\\');
            calc_convert_tobase(chaine[i], "01234567");
        }
    }
}

void display_strbis(va_list var)
{
    unsigned char *str = va_arg(var, char *);
    my_big_s(str);
}

void display_float(va_list var)
{
    my_putfloat(va_arg(var, double), 6);
}

void display_percent(va_list var)
{
    my_putchar('%');
}