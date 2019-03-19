/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** algorithm
*/

#include "../include/lem_in.h"
#include "../include/my.h"

void find_path(node_t *node)
{
    node_t *tmp = node;
    node_t *tmp_neighbor;
    static int actual_ant = 1;

    printf("#moves\n");
    while (tmp->flag != START)
        tmp = tmp->next;
    tmp_neighbor = tmp->neighbor->next;
    while (node->nbr_ants > 0) {
        tmp = node;
        while (tmp->flag != START)
            tmp = tmp->next;
        while (tmp->flag != END) {
            tmp_neighbor = tmp->neighbor->next;
            if (tmp_neighbor->neighbor->busy == 0 || tmp_neighbor->neighbor->flag == END) {
                tmp->busy = 0;
                tmp_neighbor->neighbor->busy = actual_ant;
                printf("P%d-%s\n", actual_ant, tmp_neighbor->neighbor->name);
                tmp = tmp_neighbor->neighbor;
            }
        }
        actual_ant++;
        node->nbr_ants--;
    }
}