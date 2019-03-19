/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** main
*/

#include "../include/lem_in.h"
#include "../include/my.h"

int main(void)
{
    node_t *node = malloc(sizeof(node_t));
    char *buff = NULL;
    int nbr = 0;

    buff = get_file();
    display_data(buff);
    init_node(node, buff);
    nbr = count_nodes(buff);
    for (int i = 0; i < nbr - 1; i++)
        create_list(node, buff);
    connect_nodes(node);
    find_path(node);
    return (0);
}