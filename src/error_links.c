/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** error_links
*/

#include "../include/lem_in.h"
#include "../include/my.h"

int check_links(node_t *node)
{
    node_t *tmp = find_start(node);
    node_t *next = tmp->neighbor->next;

    while (tmp != NULL) {
        while (next != NULL) {
            if (next->neighbor->flag == END) {
                return (0);
            }
            next = next->next;
        }
        tmp = go_to_next_neighbor(tmp);
        if (tmp != NULL)
            next = tmp->neighbor->next;
    }
    return (84);
}

int check_pos(node_t *node)
{
    node_t *tmp = find_start(node);
    node_t *next;

    while (tmp != NULL) {
        next = go_to_next_neighbor(tmp);
        while (next != NULL) {
            if (next->posx == tmp->posx && next->posy == tmp->posy) {
                return (84);
            }
            next = go_to_next_neighbor(next);
        }
        tmp = go_to_next_neighbor(tmp);
    }
    return (0);
}