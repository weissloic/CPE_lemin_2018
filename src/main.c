/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "include/my.h"
#include "include/lem_in.h"

void init_node(node_t *node)
{
    node->busy = 0;
    node->name = NULL;
    node->nbr_tunnels = 0;
    node->nbr_ants = 0;
    node->neighbor = NULL;
    node->next = NULL;
    node->posx = 0;
    node->posy = 0;
}

int main(void)
{
    data_t *data = malloc(sizeof(data_t));
    node_t *node = malloc(sizeof(node_t));
    char *buff;

    init_node(node);
    buff = get_file();
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
    return (0);
}