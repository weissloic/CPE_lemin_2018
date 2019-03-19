/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** algorithm
*/

#include "../include/lem_in.h"
#include "../include/my.h"

node_t *find_start(node_t *node)
{
    while (node != NULL && node->flag != START)
        node = node->next;
    return (node);
}

node_t *find_end(node_t *node)
{
    while (node != NULL && node->flag != END)
        node = node->next;
    return (node);
}

node_t *go_to_neighbor(node_t *node)
{
    if (node->neighbor->next != NULL)
        node = node->neighbor->next->neighbor;
    else
        node = find_end(node);
    return (node);
}

void move_ant(node_t **node, node_t **next, int ant)
{
    node[0]->busy = 0;
    next[0]->busy = ant;
}

void do_algo(node_t *node)
{
    const int total_ants = node->nbr_ants;
    int nbr_ants = node->nbr_ants;
    node_t *tmp = find_start(node);
    node_t *tmp_next = go_to_neighbor(tmp);
    int ant = 1;
    int actual_ant = 1;
    int loop = 1;

    printf("#moves");
    while (nbr_ants > 0) {
        tmp = find_start(node);
        tmp_next = go_to_neighbor(tmp);
        while (loop == 1) {
            if ((tmp->busy != 0 || (tmp->flag == START && nbr_ants > 1)) && (tmp_next->busy == 0 || tmp_next->flag == END)) {
                loop = 0;
            }
            else {
                tmp = go_to_neighbor(tmp);
                tmp_next = go_to_neighbor(tmp_next);
            }
        }
        if (tmp_next->flag == END)
            nbr_ants--;
        if (tmp->flag == START) {
            move_ant(&tmp, &tmp_next, ant);
            ant++;
        } else
            move_ant(&tmp, &tmp_next, tmp->busy);
        if (tmp_next->busy <= actual_ant) {
            actual_ant = 1;
            printf("\n");
        } else
            printf(" ");
        printf("P%d-%s", tmp_next->busy, tmp_next->name);
        if (tmp_next->busy > actual_ant)
            actual_ant = tmp_next->busy;
        loop = 1;
    }
    printf("\n\n");
}