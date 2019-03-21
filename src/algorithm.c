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

node_t *go_to_next_neighbor(node_t *node)
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

node_t *go_to_prev_neighbor(node_t *node, node_t *tmp)
{
    node_t *next = go_to_next_neighbor(node);

    while (my_strcmp(next->name, tmp->name) != 0 && next != NULL) {
        node = go_to_next_neighbor(node);
        next = go_to_next_neighbor(next);
    }
    return (node);
}

node_t *find_next_to_move(node_t *node)
{
    node_t *tmp = find_end(node);
    node_t *tmp_prev = go_to_prev_neighbor(node, tmp);
    int loop = 1;
    static char *name = "Lucas";

    while (loop == 1) {
        printf("\n%s %s\n", name, tmp_prev->name);
        if (((tmp_prev->busy != 0 || tmp_prev->flag == START) && (tmp->busy == 0 || tmp->flag == END)) && my_strcmp(name, tmp_prev->name) != 0) {
            loop = 0;
            name = my_strdup(tmp->name);
        }
        if (loop == 1) {
            tmp = go_to_prev_neighbor(node, tmp);
            tmp_prev = go_to_prev_neighbor(node, tmp_prev);
        }
    }
    return (tmp_prev);
}

void do_algo(node_t *node)
{
    const int total_ants = node->nbr_ants;
    int nbr_ants = node->nbr_ants;
    node_t *tmp = find_start(node);
    node_t *tmp_next = go_to_next_neighbor(tmp);
    int ant = 1;
    int actual_ant = 1;
    int loop = 1;

    printf("#moves\n");
    while (nbr_ants > 0) {
        // tmp = find_start(node);
        // tmp_next = go_to_next_neighbor(tmp);
        // while (loop == 1) {
        //     if ((tmp->busy != 0 || (tmp->flag == START && nbr_ants > 1)) && (tmp_next->busy == 0 || tmp_next->flag == END)) {
        //         loop = 0;
        //     }
        //     else {
        //         tmp = go_to_next_neighbor(tmp);
        //         tmp_next = go_to_next_neighbor(tmp_next);
        //     }
        // }
        tmp = find_next_to_move(node);
        tmp_next = go_to_next_neighbor(tmp);
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