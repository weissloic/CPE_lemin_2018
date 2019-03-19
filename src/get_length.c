/*
** EPITECH PROJECT, 2023
** Lem_in
** File description:
** Created by benjaminkuhnel,
*/

#include "../include/get_next_line.h"
#include "../include/lem_in.h"
#include "../include/my.h"

int get_length_word_tunnel2(char *buff, int i)
{
    int length = 0;

    for (; buff[i] != '\n' && buff[i] != '\0'; i++)
        length++;
    return (length);
}

int get_length_word_tunnel(char *buff, int i)
{
    int length = 0;

    for (; buff[i] != '-' && buff[i] != '\n' && buff[i] != '\0'; i++)
        length++;
    return (length);
}

int get_length_word(char *buff, int i)
{
    int length = 0;

    for (; buff[i] != ' ' && buff[i] != '\n'; i++)
        length++;
    return (length);
}

char *get_tunnel2_in_str(char *buff, int i)
{
    int length = get_length_word_tunnel2(buff, i);
    char *nbr_str = malloc(sizeof(char) * (length + 1));
    int a = 0;

    for (; buff[i] != '\n' && buff[i] != '\0'; i++) {
        if (buff[i + 1] != ' ') {
            nbr_str[a] = buff[i];
            a++;
        } else
            for (; buff[i] != '\n' && buff[i] != '\0'; i++);
    }
    nbr_str[length] = '\0';
    return (nbr_str);
}

char *get_tunnel_in_str(char *buff, int *i)
{
    int length = get_length_word_tunnel(buff, *i);
    char *nbr_str = malloc(sizeof(char) * (length + 1));
    int a = 0;

    for (; buff[i[0]] != '-' && buff[i[0]] != '\n' && buff[i[0]] != '\0'; i[0]++) {
        if (buff[i[0] + 1] != ' ') {
            nbr_str[a] = buff[i[0]];
            a++;
        } else
            for (; buff[i[0]] != '-' && buff[i[0]] != '\n' && buff[i[0]] != '\0'; i[0]++);
    }
    nbr_str[length] = '\0';
    i[0]++;
    return (nbr_str);
}