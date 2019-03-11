/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** parser
*/

#include "include/my.h"
#include "include/lem_in.h"

int get_number_of_ants(char buff[])
{
    int i = 0;
    char *nbr_str;
    int nbr = 0;

    for (; buff[i] != '\n'; i++);
    nbr_str = malloc(sizeof(char) * i);
    for (int a = 0; a < i; a++)
        nbr_str[a] = buff[a];
    nbr = my_getnbr(nbr_str);
    return (nbr);
}

void get_start_end(char buff[], data_t *data)
{
    int i = 0;
    data->start = malloc(sizeof(int) * 3);
    data->end = malloc(sizeof(int) * 3);

    for (; buff[i] != '#' || buff[i + 1] != '#' || buff[i + 2] != 's'; i++);
    for (; buff[i] != '\n'; i++);
    i++;
    data->start[0] = get_room_in_nbr(buff, &i);
    data->start[1] = get_room_in_nbr(buff, &i);
    data->start[2] = get_room_in_nbr(buff, &i);
    for (; buff[i] != '#' || buff[i + 1] != '#' || buff[i + 2] != 'e'; i++);
    for (; buff[i] != '\n'; i++);
    i++;
    data->end[0] = get_room_in_nbr(buff, &i);
    data->end[1] = get_room_in_nbr(buff, &i);
    data->end[2] = get_room_in_nbr(buff, &i);
}

int get_nbr_tunnels(char buff[])
{
    int nbr = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '-')
            nbr++;
    }
    return (nbr);
}

void get_tunnels(char buff[], data_t *data)
{
    int line = 0;

    data->tunnels = malloc(sizeof(int *) * get_nbr_tunnels(buff));
    for (int a = 0; a < get_nbr_tunnels(buff); a++)
        data->tunnels[a] = malloc(sizeof(int) * 2);
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '-') {
            i--;
            data->tunnels[line][0] = get_room_in_nbr(buff, &i);
            data->tunnels[line][1] = get_room_in_nbr(buff, &i);
            line++;
        }
    }
}