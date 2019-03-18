/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** display_data
*/

#include "../include/my.h"
#include "../include/lem_in.h"

// void display_tunnels(data_t *data, char buff[])
// {
//     my_putstr("#tunnels\n");
//     for (int i = 0; i < get_nbr_tunnels(buff); i++) {
//         my_put_nbr(data->tunnels[i][0]);
//         my_putchar('-');
//         my_put_nbr(data->tunnels[i][1]);
//         my_putchar('\n');
//     }
// }

void display_end(int *end)
{
    my_putstr("##end\n");
    for (int i = 0; i < 3; i++) {
        my_put_nbr(end[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
}

void display_start(int *start)
{
    my_putstr("##start\n");
    for (int i = 0; i < 3; i++) {
        my_put_nbr(start[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
}

// void display_rooms(data_t *data, char buff[])
// {
//     my_putstr("#rooms\n");
//     for (int i = 0; i < get_nbr_rooms(buff); i++) {
//         my_put_nbr(data->rooms[i][0]);
//         my_putchar(' ');
//         my_put_nbr(data->rooms[i][1]);
//         my_putchar(' ');
//         my_put_nbr(data->rooms[i][2]);
//         my_putchar('\n');
//     }
// }

void display_ants(int ants)
{
    my_putstr("#number_of_ants\n");
    my_put_nbr(ants);
    my_putchar('\n');
}