/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** concatenates n characters of string to the end of the dest string
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int compt = my_strlen(dest);
    int j = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (j != nb) {
            dest[compt] = src[i];
            compt++;
            j++;
        }
    }
    return (dest);
}
