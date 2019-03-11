/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** Write a function that copies n characters from a string into another.
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    return (dest);
}
