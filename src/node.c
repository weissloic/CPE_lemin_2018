/*
** EPITECH PROJECT, 2023
** Lem_in
** File description:
** Created by benjaminkuhnel,
*/

#include "../include/lem_in.h"
#include "../include/my.h"
#include "../include/get_next_line.h"

int count_nodes(char *buff)
{
    int i = 0;
    int counter = 0;
    int nbr_room = 0;

    while (buff[i] != '\0') {
        for (int j = i;
            buff[j] != '\n' && buff[j] != '\0' && buff[j + 1] != '#'; j++) {
            if (buff[j] == ' ')
                counter++;
            i = j;
        }
        i++;
        if (counter == 2)
            nbr_room++;
        counter = 0;
    }
    return (nbr_room);
}

void connect_nodes(node_t *node)
{
    node_t *tmp = node;
    node_t *tmp2 = node->next;
    node_t *tmp_neighbor;

    while (tmp != NULL) {
        tmp_neighbor = tmp->neighbor->next;
        while (tmp_neighbor != NULL) {
            tmp2 = node;
            while (tmp2 != NULL) {
                if (my_strcmp(tmp2->name, tmp_neighbor->name) == 0) {
                    tmp_neighbor->neighbor = tmp2;
                }
                tmp2 = tmp2->next;
            }
            tmp_neighbor = tmp_neighbor->next;
        }
        tmp = tmp->next;
    }
}

void init_node(node_t *node, char *buff)
{
    node->busy = 0;
    node->flag = BASIC;
    get_room(buff, node);
    node->nbr_tunnels = 0;
    node->nbr_ants = get_number_of_ants(buff);
    node->neighbor = malloc(sizeof(node_t));
    node->neighbor->name = "-1";
    node->neighbor->next = NULL;
    node->next = NULL;
    get_nbr_tunnels(node, buff);
}

void create_list(node_t *node, char *buff)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *tmp = node;

    while (tmp->next != NULL)
        tmp = tmp->next;
    init_node(new_node, buff);
    tmp->next = new_node;
}

void display_list(node_t *node)
{
    node_t *node_display = node;
    node_t *neighbor_display;

    while (node_display != NULL) {
        neighbor_display = node_display->neighbor;
        my_printf("busy: %d\n", node_display->busy);
        my_printf("name: %s\n", node_display->name);
        my_printf("flag: %d\n", node_display->flag);
        my_printf("nbr tunnels: %d\n", node_display->nbr_tunnels);
        if (node_display->nbr_tunnels != 0) {
            while (neighbor_display != NULL) {
                if (my_strcmp(neighbor_display->name, "-1") != 0) {
                    my_printf("name neighbors: %s\n", neighbor_display->name);
                    if (neighbor_display->neighbor != NULL)
                        my_printf("posx of neighbor node: %d\n",
                        neighbor_display->neighbor->posx);
                }
                neighbor_display = neighbor_display->next;
            }
        }
        my_printf("posx: %d\n", node_display->posx);
        my_printf("posy: %d\n", node_display->posy);
        node_display = node_display->next;
        my_printf("\n\n");
    }
}

