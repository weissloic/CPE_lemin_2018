/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** display one by one the characters of a string
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int letter = 0; str[letter] != '\0'; letter++)
        my_putchar(str[letter]);
    return (0);
}
