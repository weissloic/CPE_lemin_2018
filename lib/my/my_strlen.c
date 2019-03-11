/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** count the number of caraters in a string
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int compteur;

    for (compteur = 0; str[compteur] != '\0'; compteur++);
    return (compteur);
}
