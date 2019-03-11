/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** My printf.c function
*/

#include "../../include/my.h"

static void(*pt_fct[18])(va_list) =
{
        &display_int,
        &display_int,
        &display_octo,
        &display_hexa_low,
        &display_hexa_up,
        &display_bin,
        &display_unsigned,
        &display_char,
        &display_str,
        &display_strbis,
        &display_float,
        &display_float,
        &display_float,
        &display_float,
        &display_float,
        &display_pointer,
        &display_percent,
        &display_int
};

void display_unsigned(va_list var)
{
    my_putunsignd(va_arg(var, unsigned int));
}

void error_big_s(unsigned char chaine)
{
    if (chaine < 8) {
        my_putstr("\\00");
        calc_convert_tobase(chaine, "01234567");
    } else if (chaine < 32){
        my_putstr("\\0");
        calc_convert_tobase(chaine, "01234567");
    }
}

void my_putunsignd(long nbr)
{
    unsigned int rslt = 0;

    if (nbr >= 0 && nbr < 10) {
        my_putchar(nbr + 48);
    } else {
        my_put_nbr(nbr / 10);
        my_putchar((nbr % 10) + 48);
    }
}

void check_error(int j, int i, char *s, va_list var)
{
    if (j == 18) {
        my_putchar('%');
        my_putchar(s[i]);
    } else
        pt_fct[j](var);
}

void my_printf(char *s, ...)
{
    int rslt;
    va_list var;
    int j = 0;
    char tab[18] = {'d', 'i', 'o', 'x', 'X', 'b', 'u', 'c', 's', 'S', 'f',
                    'e', 'E', 'g', 'G', 'p', '%', 'n'};

    va_start(var, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            s++;
            for (j = 0; s[i] != tab[j] && j < 18; j++);
            check_error(j, i, s, var);
        } else
            my_putchar(s[i]);
    }
    va_end(var);
}
