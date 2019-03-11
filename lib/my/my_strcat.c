/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** Write a function that concatenates two strings
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int compt = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0' ; i++) {
        dest[compt] = src[i];
        compt++;
    }
    dest[compt] = '\0';
    return (dest);
}
