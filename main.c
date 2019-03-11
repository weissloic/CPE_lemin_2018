/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "include/my.h"
#include "include/lem_in.h"

int main(void)
{
    data_t *data = malloc(sizeof(data_t));
    int fd = 0;
    char buff[150];
    int size = read(fd, buff, sizeof(buff));

    if (size <= 5)
        return (84);
    data->nbr_ants = get_number_of_ants(buff);
    get_start_end(buff, data);
    get_rooms(buff, data);
    get_tunnels(buff, data);
    display_ants(data->nbr_ants);
    display_rooms(data, buff);
    display_start(data->start);
    display_end(data->end);
    display_tunnels(data, buff);
    my_putstr("#moves\n");
    close(fd);
    return (0);
}