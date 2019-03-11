/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** swap the content of twp int
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int stock;

    stock = *a;
    *a = *b;
    *b = stock;
}
